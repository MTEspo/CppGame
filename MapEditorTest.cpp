#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include "MapEditor.h"
#include "Map.h"
#include "Campaign.h"

class MapEditorTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(MapEditorTest);
    CPPUNIT_TEST(testSaveMapToFile);
    CPPUNIT_TEST(testLoadMapFromFile);
    CPPUNIT_TEST(testSaveCampaignToFile);
    CPPUNIT_TEST(testLoadCampaign);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;

    void testSaveMapToFile();
    void testLoadMapFromFile();
    void testSaveCampaignToFile();
    void testLoadCampaign();

private:
    MapEditor* editor;
};

CPPUNIT_TEST_SUITE_REGISTRATION(MapEditorTest);

void MapEditorTest::setUp() {
    editor = new MapEditor();
}

void MapEditorTest::tearDown() {
    delete editor;
}

void MapEditorTest::testSaveMapToFile() {
    Map testMap(1, 10, 10);
    std::string filename = "testMapSave.txt";
    CPPUNIT_ASSERT(editor->saveMapToFile(filename, &testMap));
}

void MapEditorTest::testLoadMapFromFile() {
    std::string filename = "testMapLoad.txt";
    Map* map = editor->loadMapFromFile(filename);
    CPPUNIT_ASSERT(map != nullptr);
    delete map;
}

void MapEditorTest::testSaveCampaignToFile() {
    Campaign testCampaign(1);
    Map testMap(1, 10, 10);
    testCampaign.addMap(&testMap);
    std::string filename = "testCampaignSave.txt";
    CPPUNIT_ASSERT(editor->saveCampaignToFile(filename, &testCampaign));
}

void MapEditorTest::testLoadCampaign() {
    std::string filename = "testCampaignLoad.txt";
    Campaign* campaign = editor->loadCampaign(filename);
    CPPUNIT_ASSERT(campaign != nullptr);
    delete campaign;
}
