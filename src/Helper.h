/**
 * Author: rodrigo
 * 2015
 */
#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <vector>
#include "ExecutionParams.h"

// Sign function
template<typename T> inline int sign(T val)
{
	return (T(0) < val) - (val < T(0));
}

class Helper
{
public:
	static void removeNANs(pcl::PointCloud<pcl::PointXYZ>::Ptr &_cloud);
	static pcl::PointCloud<pcl::Normal>::Ptr getNormals(const pcl::PointCloud<pcl::PointXYZ>::Ptr &_cloud, const double _searchRadius = -1);
	static bool getCloud(pcl::PointCloud<pcl::PointNormal>::Ptr &_cloud, const ExecutionParams &_params);
	static pcl::PointCloud<pcl::PointXYZ>::Ptr gaussianSmoothing(const pcl::PointCloud<pcl::PointXYZ>::Ptr &_cloud, const double _sigma, const double _radius);
	static pcl::PointCloud<pcl::PointXYZ>::Ptr MLSSmoothing(const pcl::PointCloud<pcl::PointXYZ>::Ptr &_cloud, const double _radius);

	static pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr createColorCloud(const pcl::PointCloud<pcl::PointNormal>::Ptr &_cloud, const uint32_t _color);
	static pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr createColorCloud(const pcl::PointCloud<pcl::PointNormal>::Ptr &_cloud, uint8_t _r, uint8_t _g, uint8_t _b);
	static float getColor(const uint8_t _r, const uint8_t _g, const uint8_t _b);
	static uint32_t getColor(const int _index);

	static bool isNumber(const std::string &_str);

private:
	Helper();
	~Helper();
};
