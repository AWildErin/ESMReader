/**
* Tests for FNV_HonestHearts.esm
*/

#include "config.h"
#include "esmreader/esm.h"

#include <gtest/gtest.h>

class FNV_HonestHearts : public testing::Test
{
protected:
    void SetUp() override 
    {
        ESMFile.Open(RESOURCES_ROOT_PATH "FNV_HonestHearts.esm");
    }

    ESM ESMFile;
};

TEST_F(FNV_HonestHearts, TES4Record)
{
    const TES4Record& Rec = ESMFile.GetTES4Record();
    
    EXPECT_FLOAT_EQ(Rec.HEDR.Version, 1.33);
    EXPECT_EQ(Rec.HEDR.NumRecords, 45312);
    EXPECT_EQ(Rec.HEDR.NextObjectId, 0xFF0119F0);

    /* CNAM */
    EXPECT_STREQ(Rec.CNAM.String.c_str(), "jfader");

    /* SNAM */
    EXPECT_STREQ(Rec.SNAM.String.c_str(), "");

    /* Master File */
    EXPECT_STREQ(Rec.MAST[0].String.c_str(), "FalloutNV.esm");
}
