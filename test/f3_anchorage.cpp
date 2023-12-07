/**
* Tests for F3_Anchorage.esm
*/

#include "config.h"
#include "esmreader/esm.h"

#include <gtest/gtest.h>

class AnchorageTest : public testing::Test
{
protected:
    void SetUp() override 
    {
        ESMFile.Open(RESOURCES_ROOT_PATH "F3_Anchorage.esm");
    }

    ESM ESMFile;
};

TEST_F(AnchorageTest, TES4Record)
{
    const TES4Record& Rec = ESMFile.GetTES4Record();
    
    /* HEDR */
    EXPECT_FLOAT_EQ(Rec.HEDR.Version, 0.94);
    EXPECT_EQ(Rec.HEDR.NumRecords, 46887);
    EXPECT_EQ(Rec.HEDR.NextObjectId, 0xFF00CF39);

    /* CNAM */
    EXPECT_STREQ(Rec.CNAM.String.c_str(), "jduvall");

    /* SNAM */
    EXPECT_STREQ(Rec.SNAM.String.c_str(), "");

    /* Master File */
    EXPECT_STREQ(Rec.MAST[0].String.c_str(), "Fallout3.esm");
}
