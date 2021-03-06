//-------------------------------------------------------------------------------------------------//
// Spacetime.cpp
// (c) Ricky Arietta 2014
// CIS 599 Masters Independent Study
// University of Pennsylvania
// Computer Graphics and Gaming Technology Program
//
// This code... 
//-------------------------------------------------------------------------------------------------//

#include "Spacetime.h"

//======================================================================================================================//
// Analytic G partial derivatives																						//
//======================================================================================================================//

matrix<double> 
Spacetime::compute_dG_dtheta1(PxU32 t) 
{
	matrix<double> dG_dtheta1(2,1);
	dG_dtheta1(0,0) = m1*g*lc1*(-sin(theta1)) + m2*g*lc2*(-sin(theta1)*cos(theta2) - cos(theta1)*sin(theta2)) + m2*g*l1*(-sin(theta1));
	dG_dtheta1(1,0) = m2*g*lc2*(-sin(theta1)*cos(theta2) - cos(theta1)*sin(theta2));
	return dG_dtheta1;
}

matrix<double>  
Spacetime::compute_dG_dtheta2(PxU32 t) 
{
	matrix<double> dG_dtheta2(2,1);
	dG_dtheta2(0,0) = m2*g*lc2 * (cos(theta1)*-sin(theta2) - sin(theta1)*cos(theta2));
	dG_dtheta2(1,0) = m2*g*lc2 * (cos(theta1)*-sin(theta2) - sin(theta1)*cos(theta2));
	return dG_dtheta2;
}

matrix<double>  
Spacetime::compute_dG_dthetaDot1(PxU32 t) 
{
	matrix<double> dG_dthetaDot1(2,1);
	dG_dthetaDot1(0,0) = 0.0;
	dG_dthetaDot1(1,0) = 0.0;
	return dG_dthetaDot1;
}

matrix<double>  
Spacetime::compute_dG_dthetaDot2(PxU32 t) 
{
	matrix<double> dG_dthetaDot2(2,1);
	dG_dthetaDot2(0,0) = 0.0;
	dG_dthetaDot2(1,0) = 0.0;
	return dG_dthetaDot2;
}

std::vector<matrix<double>> 
Spacetime::compute_dG_dX_dtheta1(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> mat1(2,1), mat2(2,1), mat3(2,1), mat4(2,1);
	mat1(0,0) = -m1*lc1*g*cos(theta1)-m2*g*lc2*cos(theta1)*cos(theta2) + m2*g*lc2*sin(theta1)*sin(theta2) - m2*g*l1*cos(theta1);
	mat1(1,0) = -m2*g*lc2*cos(theta1)*cos(theta2) + m2*g*lc2*sin(theta1)*sin(theta2);
	mat2(0,0) = m2*g*lc2*(sin(theta1)*sin(theta2) - cos(theta1)*cos(theta2));
	mat2(1,0) = m2*g*lc2*(sin(theta1)*sin(theta2) - cos(theta1)*cos(theta2));
	mat3 *= 0.0;
	mat4 *= 0.0;
	vec.push_back(mat1);
	vec.push_back(mat2);
	vec.push_back(mat3);
	vec.push_back(mat4);
	return vec;
}

std::vector<matrix<double>> 
Spacetime::compute_dG_dX_dtheta2(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> mat1(2,1), mat2(2,1), mat3(2,1), mat4(2,1);
	mat1(0,0) = m2*g*lc2*(sin(theta1)*sin(theta2) - cos(theta1)*cos(theta2));
	mat1(1,0) = m2*g*lc2*(sin(theta1)*sin(theta2) - cos(theta1)*cos(theta2));
	mat2(0,0) = m2*g*lc2*(sin(theta1)*sin(theta2) - cos(theta1)*cos(theta2));
	mat2(1,0) = m2*g*lc2*(sin(theta1)*sin(theta2) - cos(theta1)*cos(theta2));
	mat3 *= 0.0;
	mat4 *= 0.0;
	vec.push_back(mat1);
	vec.push_back(mat2);
	vec.push_back(mat3);
	vec.push_back(mat4);
	return vec;
}

std::vector<matrix<double>> 
Spacetime::compute_dG_dX_dthetaDot1(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> zeros(2,1);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	return vec;
}

std::vector<matrix<double>>  
Spacetime::compute_dG_dX_dthetaDot2(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> zeros(2,1);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	return vec;
}

//======================================================================================================================//
// Analytic C partial derivatives																						//
//======================================================================================================================//

matrix<double>  
Spacetime::compute_dC_dtheta1(PxU32 t) 
{
	matrix<double> dC_dtheta1(2,1);
	dC_dtheta1(0,0) = 0.0;
	dC_dtheta1(1,0) = 0.0;
	return dC_dtheta1;
}

matrix<double>  
Spacetime::compute_dC_dtheta2(PxU32 t) 
{
	matrix<double> dC_dtheta2(2,1);
	dC_dtheta2(0,0) = -m2*l1*lc2*cos(theta2) * (thetaDot2*thetaDot2 + 2*thetaDot1*thetaDot2);
	dC_dtheta2(1,0) =  m2*l1*lc2*cos(theta2) * (thetaDot1*thetaDot1);
	return dC_dtheta2;
}

matrix<double>  
Spacetime::compute_dC_dthetaDot1(PxU32 t) 
{
	matrix<double> dC_dthetaDot1(2,1);
	dC_dthetaDot1(0,0) = -2*m2*l1*lc2*sin(theta2)*thetaDot2;
	dC_dthetaDot1(1,0) =  2*m2*l1*lc2*sin(theta2)*thetaDot1;
	return dC_dthetaDot1;
}

matrix<double>  
Spacetime::compute_dC_dthetaDot2(PxU32 t) 
{
	matrix<double> dC_dthetaDot2(2,1);
	dC_dthetaDot2(0,0) = -2*m2*l1*lc2*sin(theta2) * (thetaDot2 + thetaDot1);
	dC_dthetaDot2(1,0) =  0;
	return dC_dthetaDot2;
}

std::vector<matrix<double>> 
Spacetime::compute_dC_dX_dtheta1(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> zeros(2,1);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	return vec;
}

std::vector<matrix<double>> 
Spacetime::compute_dC_dX_dtheta2(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> mat1(2,1);
	mat1 *= 0.0;
	matrix<double> mat2(2,1);
	mat2(0,0) = m2*l1*lc2*sin(theta2)*(thetaDot2*thetaDot2 + 2.0*thetaDot1*thetaDot2);
	mat2(1,0) = -m2*l1*lc2*sin(theta2)*thetaDot1;
	vec.push_back(mat1);
	vec.push_back(mat2);
	vec.push_back(mat1);
	vec.push_back(mat1);
	return vec;
}

std::vector<matrix<double>> 
Spacetime::compute_dC_dX_dthetaDot1(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> mat1(2,1);
	mat1(0,0) = 0.0;
	mat1(1,0) = 0.0;
	matrix<double> mat2(2,1);
	mat2(0,0) = -2.0*m2*l1*lc2*cos(theta2)*thetaDot2;
	mat2(1,0) =  2.0*m2*l1*lc2*cos(theta2)*thetaDot1;
	matrix<double> mat3(2,1);
	mat3(0,0) = 0.0;
	mat3(1,0) = 2.0*m2*l1*lc2*sin(theta2);
	matrix<double> mat4(2,1);
	mat4(0,0) = -2.0*m2*l1*lc2*sin(theta2);
	mat4(1,0) = 0.0;
	vec.push_back(mat1);
	vec.push_back(mat2);
	vec.push_back(mat3);
	vec.push_back(mat4);
	return vec;
}

std::vector<matrix<double>> 
Spacetime::compute_dC_dX_dthetaDot2(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> mat1(2,1);
	mat1(0,0) = 0.0;
	mat1(1,0) = 0.0;
	matrix<double> mat2(2,1);
	mat2(0,0) = -2.0*m2*l1*lc2*cos(theta2)*(thetaDot1 + thetaDot2);
	mat2(1,0) = 0.0;
	matrix<double> mat3(2,1);
	mat3(0,0) = -2.0*m2*l1*lc2*sin(theta2);
	mat3(1,0) = 0.0;
	matrix<double> mat4(2,1);
	mat4(0,0) = -2.0*m2*l1*lc2*sin(theta2);
	mat4(1,0) = 0.0;
	vec.push_back(mat1);
	vec.push_back(mat2);
	vec.push_back(mat3);
	vec.push_back(mat4);
	return vec;
}

//======================================================================================================================//
// Analytic MInv partial derivatives																					//
//======================================================================================================================//

matrix<double>  
Spacetime::compute_dMInv_dtheta1(PxU32 t) 
{
	matrix<double> dMInv_dtheta1(2,2);
	dMInv_dtheta1(0,0) = 0.0; dMInv_dtheta1(0,1) = 0.0;
	dMInv_dtheta1(1,0) = 0.0; dMInv_dtheta1(1,1) = 0.0;
	return dMInv_dtheta1;
}

matrix<double>  
Spacetime::compute_dMInv_dtheta2(PxU32 t) 
{
	matrix<double> dM_dtheta2(2,2);
	dM_dtheta2(0,0) = -2*(m2*l1*lc2*sin(theta2)); dM_dtheta2(0,1) = -(m2*l1*lc2*sin(theta2));
	dM_dtheta2(1,0) =   -(m2*l1*lc2*sin(theta2)); dM_dtheta2(1,1) = 0.0;
	return -MInvSequence[t] * dM_dtheta2 * MInvSequence[t];
}

matrix<double>  
Spacetime::compute_dMInv_dthetaDot1(PxU32 t) 
{
	matrix<double> dMInv_dthetaDot1(2,2);
	dMInv_dthetaDot1(0,0) = 0.0; dMInv_dthetaDot1(0,1) = 0.0;
	dMInv_dthetaDot1(1,0) = 0.0; dMInv_dthetaDot1(1,1) = 0.0;
	return dMInv_dthetaDot1;
}

matrix<double>  
Spacetime::compute_dMInv_dthetaDot2(PxU32 t) 
{
	matrix<double> dMInv_dthetaDot2(2,2);
	dMInv_dthetaDot2(0,0) = 0.0; dMInv_dthetaDot2(0,1) = 0.0;
	dMInv_dthetaDot2(1,0) = 0.0; dMInv_dthetaDot2(1,1) = 0.0;
	return dMInv_dthetaDot2;
}

std::vector<matrix<double>> 
Spacetime::compute_dMInv_dX_dtheta1(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> zeros(2,2);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	return vec;
}

std::vector<matrix<double>>  
Spacetime::compute_dMInv_dX_dtheta2(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> zeros(2,2); zeros *= 0.0;
	matrix<double> mat2(2,2);
	mat2(0,0) = -2*m2*l1*lc2*cos(theta2);  mat2(0,1) = -m2*l1*lc2*cos(theta2);
	mat2(1,0) = -m2*l1*lc2*cos(theta2);    mat2(1,1) = 0.0;
	vec.push_back(zeros);
	vec.push_back(mat2);
	vec.push_back(zeros);
	vec.push_back(zeros);
	return vec;
}

std::vector<matrix<double>> 
Spacetime::compute_dMInv_dX_dthetaDot1(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> zeros(2,2);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	return vec;
}

std::vector<matrix<double>> 
Spacetime::compute_dMInv_dX_dthetaDot2(PxU32 t) {
	std::vector<matrix<double>> vec;
	matrix<double> zeros(2,2);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	vec.push_back(0.0 * zeros);
	return vec;
}

//======================================================================================================================//
// Calculate the derivative of the cost function L with respect to the input torque vector u							//
//======================================================================================================================//

matrix<double> 
Spacetime::compute_Lu(PxU32 t)
{
	return ~uSequence[t];
}

//======================================================================================================================//
// Calculate the derivative of the cost function L with respect to the state vector X									//
//======================================================================================================================//

matrix<double> 
Spacetime::compute_Lx(PxU32 t)
{
	matrix<double> dLdx(1, DOF*joints.size()*2);
	for (int i = 0; i < DOF*joints.size()*2; i++)
		dLdx(0,i) = 0.0;
	return dLdx;
}

//======================================================================================================================//
// Calculate the derivative of the dynamics equation f with respect to the input torque vector u						//
//======================================================================================================================//

matrix<double> 
Spacetime::compute_Fu(PxU32 t)
{
	matrix<double> MInv = MInvSequence[t];
	matrix<double> dfdu(DOF*joints.size()*2, DOF*joints.size());
	for (int i = 0; i < DOF*joints.size(); i++) {
		for (int j = 0; j < DOF*joints.size(); j++) {
			dfdu(i,j) = 0.0;
			dfdu(i+DOF*joints.size(),j) = MInv(i,j);
		}
	} return dfdu;
}

//======================================================================================================================//
// Calculate the derivative of the dynamics equation f with respect to the state vector X								//
//======================================================================================================================//

matrix<double> 
Spacetime::compute_Fx(PxU32 t)
{	
	//------------------------------------------------------------------------------------------------------------------//
	// Set necessary variables for computation of partial derivatives													//
	//------------------------------------------------------------------------------------------------------------------//

	// system dependent variables
	g   = abs(gScene->getGravity().y);
	m1  = dynamic_actors[1]->getMass();
	m2  = dynamic_actors[2]->getMass();
	lc1 = joint_local_positions[0].magnitude();
	lc2 = joint_local_positions[1].magnitude();
	l1  = 2.0 * joint_local_positions[0].magnitude();
	l2  = 2.0 * joint_local_positions[1].magnitude();

	// state dependent variables
	state = stateSequence[t];
	theta1 = state(0,0);
	theta2 = state(1,0);
	thetaDot1 = state(2,0);
	thetaDot2 = state(3,0);

	//------------------------------------------------------------------------------------------------------------------//
	// compute dG_dX, the derivative of the gravitational torque matrix w.r.t. to the state vector						//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	matrix<double> dG_dtheta1    = compute_dG_dtheta1(t);
	matrix<double> dG_dtheta2    = compute_dG_dtheta2(t);
	matrix<double> dG_dthetaDot1 = compute_dG_dthetaDot1(t);
	matrix<double> dG_dthetaDot2 = compute_dG_dthetaDot2(t);

	std::vector<matrix<double>> dG_dX;
	dG_dX.push_back(dG_dtheta1);
	dG_dX.push_back(dG_dtheta2);
	dG_dX.push_back(dG_dthetaDot1);
	dG_dX.push_back(dG_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dC_dX, the derivative of the centripetal torque matrix w.r.t. to the state vector						//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	matrix<double> dC_dtheta1    = compute_dC_dtheta1(t);
	matrix<double> dC_dtheta2    = compute_dC_dtheta2(t);
	matrix<double> dC_dthetaDot1 = compute_dC_dthetaDot1(t);
	matrix<double> dC_dthetaDot2 = compute_dC_dthetaDot2(t);

	std::vector<matrix<double>> dC_dX;
	dC_dX.push_back(dC_dtheta1);
	dC_dX.push_back(dC_dtheta2);
	dC_dX.push_back(dC_dthetaDot1);
	dC_dX.push_back(dC_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dMinv_dx, the derivative of the inverse mass matrix w.r.t. to the state vector							//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	matrix<double> dMInv_dtheta1    = compute_dMInv_dtheta1(t);
	matrix<double> dMInv_dtheta2    = compute_dMInv_dtheta2(t);
	matrix<double> dMInv_dthetaDot1 = compute_dMInv_dthetaDot1(t);
	matrix<double> dMInv_dthetaDot2 = compute_dMInv_dthetaDot2(t);

	std::vector<matrix<double>> dMInv_dX;
	dMInv_dX.push_back(dMInv_dtheta1);
	dMInv_dX.push_back(dMInv_dtheta2);
	dMInv_dX.push_back(dMInv_dthetaDot1);
	dMInv_dX.push_back(dMInv_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// dfdx = |df1/dx| = |        0         |         I          |														//
	//		  |df2/dx|	 | dMInv_dX*(u+C+G) - Minv*(dC_dx+dG_dx) |														//
	//------------------------------------------------------------------------------------------------------------------//

	matrix<double> u = uSequence[t];
	matrix<double> C = CSequence[t];
	matrix<double> G = GSequence[t];
	matrix<double> MInv = MInvSequence[t];

	// df1/dx
	matrix<double> df1dx(DOF*joints.size(), DOF*joints.size()*2);
	for (int i = 0; i < DOF*joints.size(); i++) {
		for (int j = 0; j < DOF*joints.size(); j++) {
			df1dx(i,j) = 0;
			if (i == j) df1dx(i,j+DOF*joints.size()) = 1;
			else		df1dx(i,j+DOF*joints.size()) = 0;
		}
	}

	// df2/dx
	matrix<double> df2dx(DOF*joints.size(), DOF*joints.size()*2);
	for (int i = 0; i < DOF*joints.size()*2; i++) {
		matrix<double> column_i = (dMInv_dX[i]*u) - (dMInv_dX[i]*C + MInv*dC_dX[i]) - (dMInv_dX[i]*G + MInv*dG_dX[i]);
		for (int j = 0; j < DOF*joints.size(); j++) {
			df2dx(j,i) = column_i(j,0);
		}
	}
	
	// df/dx
	matrix<double> dfdx(DOF*joints.size()*2, DOF*joints.size()*2);
	for (int i = 0; i < DOF*joints.size(); i++) {
		for (int j = 0; j < DOF*joints.size()*2; j++) {
			dfdx(i,j) = df1dx(i,j);
			dfdx(i+DOF*joints.size(),j) = df2dx(i, j);
		}
	}
	
	return I(4) + deltaT*dfdx;
}

matrix<double> 
Spacetime::compute_Luu(PxU32 t) {
	matrix<double> Luu(2,2);
	Luu(0,0) = 1.0; Luu(0,1) == 0.0;
	Luu(1,0) = 0.0; Luu(1,1) == 1.0;
	return Luu;
}

matrix<double> 
Spacetime::compute_Lxx(PxU32 t) {
	matrix<double> Lxx(4,4);
	return (0.0 * Lxx);
}

matrix<double> 
Spacetime::compute_Lux(PxU32 t) {
	matrix<double> Lux(2,4);
	return (0.0 * Lux);
}

matrix<double> 
Spacetime::compute_Lxu(PxU32 t) {
	matrix<double> Lxu(4,2);
	return (0.0 * Lxu);
}

std::vector<matrix<double>>
Spacetime::compute_Fxx(PxU32 t) 
{
	//------------------------------------------------------------------------------------------------------------------//
	// Set necessary variables for computation of partial derivatives													//
	//------------------------------------------------------------------------------------------------------------------//

	// stored system matrices
	matrix<double> u = uSequence[t];
	matrix<double> G = GSequence[t];
	matrix<double> C = CSequence[t];
	matrix<double> MInv = MInvSequence[t];

	// system dependent variables
	g   = abs(gScene->getGravity().y);
	m1  = dynamic_actors[1]->getMass();
	m2  = dynamic_actors[2]->getMass();
	lc1 = joint_local_positions[0].magnitude();
	lc2 = joint_local_positions[1].magnitude();
	l1  = 2.0 * joint_local_positions[0].magnitude();
	l2  = 2.0 * joint_local_positions[1].magnitude();

	// state dependent variables
	state = stateSequence[t];
	theta1 = state(0,0);
	theta2 = state(1,0);
	thetaDot1 = state(2,0);
	thetaDot2 = state(3,0);

	//------------------------------------------------------------------------------------------------------------------//
	// compute dG_dX, the derivative of the gravitational torque matrix w.r.t. to the state vector						//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	matrix<double> dG_dtheta1    = compute_dG_dtheta1(t);
	matrix<double> dG_dtheta2    = compute_dG_dtheta2(t);
	matrix<double> dG_dthetaDot1 = compute_dG_dthetaDot1(t);
	matrix<double> dG_dthetaDot2 = compute_dG_dthetaDot2(t);

	std::vector<matrix<double>> dG_dX;
	dG_dX.push_back(dG_dtheta1);
	dG_dX.push_back(dG_dtheta2);
	dG_dX.push_back(dG_dthetaDot1);
	dG_dX.push_back(dG_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dC_dX, the derivative of the centripetal torque matrix w.r.t. to the state vector						//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	matrix<double> dC_dtheta1    = compute_dC_dtheta1(t);
	matrix<double> dC_dtheta2    = compute_dC_dtheta2(t);
	matrix<double> dC_dthetaDot1 = compute_dC_dthetaDot1(t);
	matrix<double> dC_dthetaDot2 = compute_dC_dthetaDot2(t);

	std::vector<matrix<double>> dC_dX;
	dC_dX.push_back(dC_dtheta1);
	dC_dX.push_back(dC_dtheta2);
	dC_dX.push_back(dC_dthetaDot1);
	dC_dX.push_back(dC_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dMinv_dx, the derivative of the inverse mass matrix w.r.t. to the state vector							//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	matrix<double> dMInv_dtheta1    = compute_dMInv_dtheta1(t);
	matrix<double> dMInv_dtheta2    = compute_dMInv_dtheta2(t);
	matrix<double> dMInv_dthetaDot1 = compute_dMInv_dthetaDot1(t);
	matrix<double> dMInv_dthetaDot2 = compute_dMInv_dthetaDot2(t);

	std::vector<matrix<double>> dMInv_dX;
	dMInv_dX.push_back(dMInv_dtheta1);
	dMInv_dX.push_back(dMInv_dtheta2);
	dMInv_dX.push_back(dMInv_dthetaDot1);
	dMInv_dX.push_back(dMInv_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dG_dX_dX, the second derivative of the gravitational torque matrix w.r.t. to the state vector			//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	std::vector<std::vector<matrix<double>>> dG_dX_dX;
	std::vector<matrix<double>> dG_dX_dtheta1 = compute_dG_dX_dtheta1(t);
	std::vector<matrix<double>> dG_dX_dtheta2 = compute_dG_dX_dtheta2(t);
	std::vector<matrix<double>> dG_dX_dthetaDot1 = compute_dG_dX_dthetaDot1(t);
	std::vector<matrix<double>> dG_dX_dthetaDot2 = compute_dG_dX_dthetaDot2(t);
	dG_dX_dX.push_back(dG_dX_dtheta1);
	dG_dX_dX.push_back(dG_dX_dtheta2);
	dG_dX_dX.push_back(dG_dX_dthetaDot1);
	dG_dX_dX.push_back(dG_dX_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dC_dX_dX, the second derivative of the centripetal torque matrix w.r.t. to the state vector				//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	std::vector<std::vector<matrix<double>>> dC_dX_dX;
	std::vector<matrix<double>> dC_dX_dtheta1 = compute_dC_dX_dtheta1(t);
	std::vector<matrix<double>> dC_dX_dtheta2 = compute_dC_dX_dtheta2(t);
	std::vector<matrix<double>> dC_dX_dthetaDot1 = compute_dC_dX_dthetaDot1(t);
	std::vector<matrix<double>> dC_dX_dthetaDot2 = compute_dC_dX_dthetaDot2(t);
	dC_dX_dX.push_back(dC_dX_dtheta1);
	dC_dX_dX.push_back(dC_dX_dtheta2);
	dC_dX_dX.push_back(dC_dX_dthetaDot1);
	dC_dX_dX.push_back(dC_dX_dthetaDot2);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dMinv_dx_dX, the second derivative of the inverse mass matrix w.r.t. to the state vector					//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	std::vector<std::vector<matrix<double>>> dMInv_dX_dX;
	std::vector<matrix<double>> dMInv_dX_dtheta1 = compute_dMInv_dX_dtheta1(t);
	std::vector<matrix<double>> dMInv_dX_dtheta2 = compute_dMInv_dX_dtheta2(t);
	std::vector<matrix<double>> dMInv_dX_dthetaDot1 = compute_dMInv_dX_dthetaDot1(t);
	std::vector<matrix<double>> dMInv_dX_dthetaDot2 = compute_dMInv_dX_dthetaDot2(t);
	dMInv_dX_dX.push_back(dMInv_dX_dtheta1);
	dMInv_dX_dX.push_back(dMInv_dX_dtheta2);
	dMInv_dX_dX.push_back(dMInv_dX_dthetaDot1);
	dMInv_dX_dX.push_back(dMInv_dX_dthetaDot2);

	//------------------------------------------------------------------------------------------------------------------//
	// compute df2x w.r.t. each element of X, which constitute the bottom 2 rows of each matrix in the final vector,	//
	// and concatenate into vector of matrices
	//------------------------------------------------------------------------------------------------------------------//
	
	std::vector<matrix<double>> Fxx;

	// fxtheta1
	matrix<double> fx2theta1 = vec2mat(vectorMatrixProduct(dMInv_dX_dtheta1,(u-C-G))) 
							   - 2.0*vec2mat((matrixVectorProduct(dMInv_dtheta1,(vectorSum(dC_dX,dG_dX))))) 
							   - vec2mat(matrixVectorProduct(MInv, (vectorDifference(dC_dX_dtheta1, dG_dX_dtheta1))));
	matrix<double> fxtheta1(4,4);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxtheta1(i,j) = 0.0;
		}
	} for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxtheta1(i+2,j) = fx2theta1(i,j);
		}
	} Fxx.push_back(deltaT * fxtheta1);
	

	// fxtheta2
	matrix<double> fx2theta2 = vec2mat(vectorMatrixProduct(dMInv_dX_dtheta2,(u-C-G))) 
							   - 2.0*vec2mat((matrixVectorProduct(dMInv_dtheta2,(vectorSum(dC_dX,dG_dX))))) 
							   - vec2mat(matrixVectorProduct(MInv, (vectorDifference(dC_dX_dtheta2, dG_dX_dtheta2))));
	matrix<double> fxtheta2(4,4);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxtheta2(i,j) = 0.0;
		}
	} for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxtheta2(i+2,j) = fx2theta2(i,j);
		}
	} Fxx.push_back(deltaT * fxtheta2);
	
	// fxthetaDot1
	matrix<double> fx2thetaDot1 = vec2mat(vectorMatrixProduct(dMInv_dX_dthetaDot1,(u-C-G))) 
								  - 2.0*vec2mat((matrixVectorProduct(dMInv_dthetaDot1,(vectorSum(dC_dX,dG_dX))))) 
							      - vec2mat(matrixVectorProduct(MInv, (vectorDifference(dC_dX_dthetaDot1, dG_dX_dthetaDot1))));
	matrix<double> fxthetaDot1(4,4);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxthetaDot1(i,j) = 0.0;
		}
	} for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxthetaDot1(i+2,j) = fx2thetaDot1(i,j);
		}
	} Fxx.push_back(deltaT * fxthetaDot1);
	
	// fxthetaDot2
	matrix<double> fx2thetaDot2 = vec2mat(vectorMatrixProduct(dMInv_dX_dthetaDot2,(u-C-G))) 
							      - 2.0*vec2mat((matrixVectorProduct(dMInv_dthetaDot2,(vectorSum(dC_dX,dG_dX))))) 
							      - vec2mat(matrixVectorProduct(MInv, (vectorDifference(dC_dX_dthetaDot2, dG_dX_dthetaDot2))));
	matrix<double> fxthetaDot2(4,4);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxthetaDot2(i,j) = 0.0;
		}
	} for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			fxthetaDot2(i+2,j) = fx2thetaDot2(i,j);
		}
	} Fxx.push_back(deltaT * fxthetaDot2);
	
	return Fxx;
}

std::vector<matrix<double>> 
Spacetime::compute_Fux(PxU32 t) {
	std::vector<matrix<double>> Fux;
	matrix<double> dMInv_dtheta2 = compute_dMInv_dtheta2(t);
	matrix<double> mat(4,2); mat *= 0.0;
	mat(2,0) = dMInv_dtheta2(0,0);  mat(2,1) = dMInv_dtheta2(0,1);
	mat(3,0) = dMInv_dtheta2(1,0);  mat(3,1) = dMInv_dtheta2(1,1);
	Fux.push_back(0.0 * mat);
	Fux.push_back(mat);
	Fux.push_back(0.0 * mat);
	Fux.push_back(0.0 * mat);
	return Fux;
}

std::vector<matrix<double>> 
Spacetime::compute_Fxu(PxU32 t) 
{
	//------------------------------------------------------------------------------------------------------------------//
	// Set necessary variables for computation of partial derivatives													//
	//------------------------------------------------------------------------------------------------------------------//

	// system dependent variables
	g   = abs(gScene->getGravity().y);
	m1  = dynamic_actors[1]->getMass();
	m2  = dynamic_actors[2]->getMass();
	lc1 = joint_local_positions[0].magnitude();
	lc2 = joint_local_positions[1].magnitude();
	l1  = 2.0 * joint_local_positions[0].magnitude();
	l2  = 2.0 * joint_local_positions[1].magnitude();

	// state dependent variables
	state = stateSequence[t];
	theta1 = state(0,0);
	theta2 = state(1,0);
	thetaDot1 = state(2,0);
	thetaDot2 = state(3,0);
	
	//------------------------------------------------------------------------------------------------------------------//
	// compute dMinv_dx, the derivative of the inverse mass matrix w.r.t. to the state vector							//
	// and build full 3D derivative matrix from partials																//
	//------------------------------------------------------------------------------------------------------------------//
	
	matrix<double> dMInv_dtheta1    = compute_dMInv_dtheta1(t);
	matrix<double> dMInv_dtheta2    = compute_dMInv_dtheta2(t);
	matrix<double> dMInv_dthetaDot1 = compute_dMInv_dthetaDot1(t);
	matrix<double> dMInv_dthetaDot2 = compute_dMInv_dthetaDot2(t);
		
	std::vector<matrix<double>> Fxu;
	
	matrix<double> Fxu1(4,4);
	Fxu1 = 0.0* Fxu1;
	Fxu1(2,0) = dMInv_dtheta1(0,0); Fxu1(2,1) = dMInv_dtheta1(0,0); Fxu1(2,2) = dMInv_dthetaDot1(0,0); Fxu1(2,3) = dMInv_dthetaDot2(0,0);
	Fxu1(3,0) = dMInv_dtheta1(1,0); Fxu1(3,1) = dMInv_dtheta2(1,0); Fxu1(3,2) = dMInv_dthetaDot1(1,0); Fxu1(3,3) = dMInv_dthetaDot2(1,0);
	Fxu.push_back(Fxu1);

	matrix<double> Fxu2(4,4);
	Fxu2 = 0.0* Fxu2;
	Fxu2(2,0) = dMInv_dtheta1(0,1); Fxu2(2,1) = dMInv_dtheta1(0,1); Fxu2(2,2) = dMInv_dthetaDot1(0,1); Fxu2(2,3) = dMInv_dthetaDot2(0,1);
	Fxu2(3,0) = dMInv_dtheta1(1,1); Fxu2(3,1) = dMInv_dtheta2(1,1); Fxu2(3,2) = dMInv_dthetaDot1(1,1); Fxu2(3,3) = dMInv_dthetaDot2(1,1);
	Fxu.push_back(Fxu2);

	return Fxu;
}

std::vector<matrix<double>>
Spacetime::compute_Fuu(PxU32 t) {
	std::vector<matrix<double>> Fuu;
	matrix<double> zeros(4,2);
	Fuu.push_back(0.0 * zeros);
	Fuu.push_back(0.0 * zeros);
	return Fuu;
}