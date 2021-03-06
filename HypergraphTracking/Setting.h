#pragma once

#include "defines.hpp"
#include <vector>

class CSetting
{
public:
	CSetting(void);
	CSetting(const char *strSettingPath);
	~CSetting(void);

	bool LoadSetting(const char *strSettingPath);
	int  numCams(void)       { return numCams_; }
	int  startFrameIdx(void) { return startFrameIdx_; }
	int  endFrameIdx(void)   { return endFrameIdx_; }
	int  numFrames(void)     { return numFrames_; }
	int  GetCamIdx(int idx)  { return cameraIdxs_[idx]; }
	int  dispTrajectoryLength(void) { return dispTrajectoryLength_; }
	std::string GetDatasetPath(void)         { return strDatasetPath_; }	
	std::string GetCalibrationPath(void)     { return strCalibrationPath_; }
	std::string GetResultPath(void)          { return strResultPath_; }
	std::string GetViewPath(int camIdx)      { return vecStrViewPaths_[camIdx]; }
	std::string GetDetectionPath(int camIdx) { return vecStrDetectionPaths_[camIdx]; }
	std::string GetGTPath(void)              { return strGroundTruthPath_; }
	PETS_SCENARIO GetScenarioNumber(void)    { return scenarioNumber_; }
	stHypergraphTrackingParams* GetParamHGT(void) { return &paramHGT_; }

private:
	void ParseArray(const std::string strInput, std::vector<int> &output);

private:
	bool bInit_;
	int numCams_;
	PETS_SCENARIO scenarioNumber_;
	int startFrameIdx_;
	int endFrameIdx_;
	int numFrames_;
	std::vector<int> cameraIdxs_;
	std::string strDatasetPath_;
	std::string strDatasetScenario_;	
	std::string strCalibrationPath_;
	std::string strGroundTruthPath_;
	std::string strResultPath_;
	std::vector<std::string> vecStrViewPaths_;
	std::vector<std::string> vecStrDetectionPaths_;
	stHypergraphTrackingParams paramHGT_;

	// visualization
	int dispTrajectoryLength_;
};

