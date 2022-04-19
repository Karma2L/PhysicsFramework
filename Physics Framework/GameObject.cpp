#include "GameObject.h"


GameObject::GameObject(string type, Appearance* appearance, Transform* ap_transform, ParticleModel* particleModel)
{
	_transform = ap_transform;
	_appearance = appearance;
	_particleModel = particleModel;
	
	//Transform _textureRV = nullptr;
	_type = type;
	if (_particleModel)
	{
		_particleModel->SetMass(5.0f);
	}
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	// Calculate world matrix
	//transform.Update(); Auto Change to ->
	
	_transform->Update();

	if (_particleModel)
	{
		_particleModel->Update(t);
		_transform = _particleModel->GetTransform();
		_particleModel->PreventsFromFalling();


	}


	
	if (_type == "Cube ")
	{
		//debug.debugLog(t);
	}


	
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
