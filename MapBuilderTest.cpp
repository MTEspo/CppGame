#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include "LeveledMapBuilder.h"
#include "MapEditor.h"

class LeveledMapBuilderTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(LeveledMapBuilderTest);
    CPPUNIT_TEST(testBuildMap);
    CPPUNIT_TEST(testGetMap);
    CPPUNIT_TEST(testAdaptMapToLevel);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;

    void testBuildMap();
    void testGetMap();
    void testAdaptMapToLevel();

private:
    LeveledMapBuilder* builder;
    std::string testFilename;
    int testLevel;
};

CPPUNIT_TEST_SUITE_REGISTRATION(LeveledMapBuilderTest);

void LeveledMapBuilderTest::setUp() {
    testFilename = "testMap.txt";
    testLevel = 5;
    builder = new LeveledMapBuilder(testFilename, testLevel);
}

void LeveledMapBuilderTest::tearDown() {
    delete builder;
    builder = nullptr;
}

void LeveledMapBuilderTest::testBuildMap() {
    CPPUNIT_ASSERT_NO_THROW(builder->buildMap());
}

void LeveledMapBuilderTest::testGetMap() {
    builder->buildMap();
    Map* map = builder->getMap();
    CPPUNIT_ASSERT(map != nullptr);
}

void LeveledMapBuilderTest::testAdaptMapToLevel() {
    builder->buildMap();
    Map* map = builder->getMap();
    int opponentCount = 0;
    for (int y = 0; y < map->getHeight(); ++y) {
        for (int x = 0; x < map->getWidth(); ++x) {
            if (map->getCellType(x, y) == CellType::OPPONENT) {
                ++opponentCount;
            }
        }
    }
    CPPUNIT_ASSERT_EQUAL(testLevel, opponentCount);
}
