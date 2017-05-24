#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	VectorXd rmse(4);
	rmse<<0.0,0.0,0.0,0.0;

	for (int ii = 0;ii < estimations.size();ii++){
		VectorXd diff = estimations[ii] - ground_truth[ii];
		diff = diff.array() * diff.array();
		rmse = rmse + diff;
	}
	rmse = rmse/estimations.size();
	rmse = rmse.array().sqrt();

	return rmse;
}
