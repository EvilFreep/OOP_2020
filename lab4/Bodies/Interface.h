#pragma once
#include "CBody.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
#include "includes.h"

const int CALCULATE_TYPE = 0;
const int CONE_TYPE = 1;
const int CYLINDER_TYPE = 2;
const int PARALLELEPIPED_TYPE = 3;
const int SPHERE_TYPE = 4;

const std::string BODY_TYPE_MES = "Enter body type: \n\t1 - Cone\n\t2 - Cylinder\n\t3 - Parallelepiped\n\t4 - Sphere\n\t0 - End and calculate results\n";
const std::string UNKNOWN_TYPE_ERR = "Unknown type\n";
const std::string LIGHTEST_BODY_IN_WATER = "Lightest body in water: ";
const std::string BIGGEST_WEIGHT = "Body with biggest weight: ";
const std::string DENSITY_MES = "Enter density: ";
const std::string SPHERE_RADIUS_MES = "Enter Sphere radius: ";
const std::string CONE_BASERADIUS_MES = "Enter Cone baseradius: ";
const std::string CONE_HEIGHT_MES = "Enter Cone height: ";
const std::string CYLINDER_HEIGHT_MES = "Enter Cylinder height: ";
const std::string CYLINDER_BASERADIUS_MES = "Enter Cylinder baseradius: ";
const std::string PARALLELEPIPED_WIDTH_MES = "Enter Parallelepiped width: ";
const std::string PARALLELEPIPED_HEIGHT_MES = "Enter Parallelepiped height: ";
const std::string PARALLELEPIPED_DEPTH_MES = "Enter Parallelepiped depth: ";

bool CheckCorrectType(int& type);
shared_ptr<CBody> FindMaxMass(const vector<shared_ptr<CBody>>& bodies);
shared_ptr<CBody> FindMinResultingForceInWater(const vector<shared_ptr<CBody>>& bodies);
void FillBodiesVector(vector<shared_ptr<CBody>>& bodies, istream& input, ostream& output);
void BodyController(vector<shared_ptr<CBody>> bodies, istream& input, ostream& output);
void PrintInf(const shared_ptr<CBody>& bodies, ostream& output);