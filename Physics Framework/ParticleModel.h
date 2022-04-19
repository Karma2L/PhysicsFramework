#pragma once

#define DRAG_COEFFICIENT 1.05f
#define REFERENCE_AREA 4
#define DENSITY_OF_AIR 1.225


#include "Transform.h"
class ParticleModel
{
public:
	ParticleModel(Transform* transform,Vector3D velocity,Vector3D acceleration, bool useConstAcceleration, bool useVelocity, float mass, bool useGravity);
	~ParticleModel();
	
	//----------------- Updates---------------------------
	void Update(float t);
	void UpdateState(float t);
	void UpdateNetForce();
	void UpdateAccel();
	
	//-------------------Tranform------------------------

	Transform* GetTransform() const { return _transform; }

	//  ----------------Velocity----------------------
	Vector3D GetVelocity() const { return _velocity; }
	void moveConstVelocity(float t);
	void SetVelocity(Vector3D velocity) { _velocity = velocity; }
	void SetVelocity(float x, float y, float z) { _velocity.x = x; _velocity.y = y; _velocity.z = z; }
	
	// ---------------------Acceleration -------------------------
	Vector3D GetAcceleration() const { return _acceleration; }
	void moveConstAcceleration(float t);
	void SetAcceleration(Vector3D accelaration) { _acceleration = accelaration; }
	void SetAcceleration(float x, float y, float z) { _acceleration.x = x; _acceleration.y = y; _acceleration.z = z; }
	
	// --------------------------Forces-----------------------------------------
	Vector3D GetNetForce() const { return _netforce; }
	void SetNetForce(Vector3D netforce) { _netforce = netforce; }
	void SetNetForce(float x, float y, float z) { _netforce.x = x; _netforce.y = y; _netforce.z = z; }
	
	void SetThrustForce(Vector3D thrust) { _thrust = thrust; }
	void SetThrustForce(float x, float y, float z) { _thrust.x = x; _thrust.y = y; _thrust.z = z;}

	//


	//------------------------------Gravity---------------------------------------------

	void ActivateGravity(bool gravity);

	// ------------------------Position on Plane-------------------------------------
	void move(float t);
	void SetPositionOnPlane(Vector3D positionOnPlane) { _positionOnPlane = positionOnPlane; }
	void SetPositionOnPlane(float x, float y, float z) { _positionOnPlane.x = x; _positionOnPlane.y = y; _positionOnPlane.z = z; }
	//-----------------------------Mass-----------------------------------
	float GetMass() { return _mass; };
	void SetMass(float _masstoset) { _mass = _masstoset; }


	//---------------------------Using Constant Acceleration---------------------------------------
	void SetUsingConstAccel(bool condition);

	//-----------Constraints--------
	void PreventsFromFalling();

private:
	float _mass;
	bool _useConstAcceleration;
	bool _useConstVelocity;
	bool _useGravity;

	Transform* _transform;
	Vector3D _velocity;
	Vector3D _acceleration;
	Vector3D _gravity;
	Vector3D _netforce;
	Vector3D _friction;
	Vector3D _thrust;
	Vector3D _force;
	Vector3D _positionOnPlane;
	Vector3D _weight;
	Vector3D _upForce;

	//F= ma    e.g. mass = 10.0g acceleration = 0,-9.81,0 ma = 10*0,10*-9.81,10*0

protected:

};

