#include "ParticleModel.h"
#include <Windows.h>
ParticleModel::ParticleModel(Transform* transform, Vector3D velocity, Vector3D acceleration, bool useConstAcceleration, bool useVelocity, float mass, bool useGravity)
{
	_transform = transform;
	_velocity = velocity;
	_acceleration = acceleration;
	_useConstAcceleration = useConstAcceleration;

	_netforce = Vector3D(0.0f, 0.0f, 0.0f);

	_mass = mass;

	_gravity = Vector3D(0.0f, -9.81f, 0.0f);

	_velocity = Vector3D(0.0f, 0.0f, 0.0f);

	_useGravity = useGravity;


	_weight.y = _mass * _gravity.y;
	

	//_upForce = Vector3D(0.0f, 9.81f, 0.0f);
}

ParticleModel::~ParticleModel()
{
	delete _transform;
}

void ParticleModel::Update(float t)
{
	if (_useConstAcceleration == true)
	{
		UpdateState(t);
	}
	else
	{
		moveConstVelocity(t);
	}


	//UpdateState(t);
	//UpdateNetForce();
	//UpdateAccel();
	//move(t);


	//if (_useConstVelocity == true)
	//{
	//	moveConstVelocity(t);
	//}

	Reset();
}



void ParticleModel::moveConstVelocity(float t)
{
	Vector3D position = _transform->GetPosition();
	position = (position + _velocity * t);

	_transform->SetPosition(position);
}
void ParticleModel::moveConstAcceleration(float t)
{
	Vector3D position = _transform->GetPosition();

	position.x = position.x + _velocity.x * t + 0.5f * _acceleration.x * t * t ; 
	position.y = position.y + _velocity.y * t + 0.5f * _acceleration.y * t * t;
	position.z = position.z + _velocity.z * t + 0.5f * _acceleration.z * t * t;

	_velocity = _velocity + _acceleration * t;

	_transform->SetPosition(position);
}




void ParticleModel::UpdateState(float t)
{
	UpdateNetForce();
	UpdateAccel();
	move(t);	
}

void ParticleModel::UpdateNetForce()
{
	/*calculate thrust force
	 _netforce.x += _thrustforce.x;
	 _netforce.y += _thrustforce.y;
	calculatedrag
	calculate friction*/

	Vector3D forces[] = { _thrust, _friction, _drag };
	

	for(Vector3D& force : forces)
	{
		_netforce.x += force.x;
		_netforce.y += force.y;
		_netforce.z += force.z;
	}
		

	
}

void ParticleModel::UpdateAccel()
{
	_acceleration.x = _netforce.x / _mass; // Acceleration = Force / Mass
	_acceleration.y = _netforce.y / _mass;
	_acceleration.z = _netforce.z / _mass;

	if (_useGravity)
	{
		_acceleration.y += _weight.y;
	}
	auto s = std::to_string(_acceleration.y) + "\n";
	std::wstring  ws(s.begin(), s.end());
	OutputDebugString(ws.c_str());
}


Vector3D ParticleModel::CalculateDrag()
{
	_drag = Vector3D();
	_drag.x = DRAG_COEFFICIENT * REFERENCE_AREA * DENSITY_OF_AIR * _velocity.x * _velocity.x * 0.5;
	_drag.y = DRAG_COEFFICIENT * REFERENCE_AREA * DENSITY_OF_AIR * _velocity.y * _velocity.y * 0.5;
	_drag.z = DRAG_COEFFICIENT * REFERENCE_AREA * DENSITY_OF_AIR * _velocity.z * _velocity.z * 0.5;

	return _drag;
}

void ParticleModel::Reset()
{
	_acceleration = Vector3D(0.0f, 0.0f, 0.0f);
	_force = Vector3D(0.0f, 0.0f, 0.0f);
}

void ParticleModel::ActivateGravity(bool gravity)
{
	_useGravity = gravity;
}

void ParticleModel::move(float t)
{

	_velocity = _velocity + _acceleration * t;

	Vector3D position = _transform->GetPosition();
	
	position.x = position.x + _velocity.x * t + 0.5 * _acceleration.x * t * t;
	position.y = position.y + _velocity.y * t + 0.5 * _acceleration.y * t * t;
	position.z = position.z + _velocity.z * t + 0.5 * _acceleration.z * t * t;

	_transform->SetPosition(position);
}

void ParticleModel::SetUsingConstAccel(bool condition)
{
	_useConstAcceleration = condition;
}


void ParticleModel::PreventsFromFalling()
{
	auto pos = _transform->GetPosition();
	if (pos.y < 0.5f)
		_transform->SetPosition(pos.x, 0.5f, pos.z);
}



