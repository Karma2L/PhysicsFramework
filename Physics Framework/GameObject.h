#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Debug.h"
#include "Transform.h"
#include "Appearance.h"
#include "ParticleModel.h"


using namespace DirectX;
using namespace std;



class GameObject 
{
public:
	GameObject(string type, Appearance* appearance, Transform* ap_transform, ParticleModel* particleModel);
	~GameObject();

	// Setters and Getters for position/rotation/scale
	string GetType() const { return _type; }
	void Update(float t);
	void Draw(ID3D11DeviceContext* pImmediateContext);
	Transform* GetTransform() { return _transform; }
	Appearance* GetAppearance() { return _appearance; }
	ParticleModel* GetParticleModel() { return _particleModel; }


private:
	float _mass;
	string _type;
	Transform* _transform;
	Appearance* _appearance;
	ParticleModel* _particleModel;
	Debug debug;

	
	
	//int _objectType;
};

