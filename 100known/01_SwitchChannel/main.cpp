//
// Created by huluwa on 20-3-18.
//

#include "SwitchChannel.h"
#include "tool.h"


int main()
{
    // 默认读取为BGR
    cv::Mat src = cv::imread("../../test.jpg");
    if(src.empty())
    {
        std::cout << "Load src img failed." << std::endl;
        return -1;
    }

    cv::Mat dst1 = Run("SwitchByManual", SwitchByManual, src);
    cv::hconcat(src, dst1, dst1);
    Show("SwitchByManual", dst1);

    cv::Mat dst2 = Run("SwitchBySplitAndMerge", SwitchBySplitAndMerge, src);
    cv::hconcat(src, dst2, dst2);
    Show("SwitchBySplitAndMerge", dst2);

    cv::Mat dst3 = Run("SwitchByMixChannels", SwitchByMixChannels, src);
    cv::hconcat(src, dst3, dst3);
    Show("SwitchByMixChannels", dst3);

    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}