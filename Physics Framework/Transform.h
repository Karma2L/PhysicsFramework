#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Debug.h"
#include "Vector3d.h"


using namespace DirectX;

class GameObject;

class Transform
{
public:
	void SetPosition(Vector3D position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	void SetScale(Vector3D scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }


	void SetRotation(Vector3D rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }


	Vector3D GetScale() const { return _scale; }
	Vector3D GetRotation() const { return _rotation; }
	Vector3D GetPosition() const { return _position; }
	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }
	
	Transform();
	~Transform();

	void Update();

private:

	Vector3D _position;
	Vector3D _rotation;
	Vector3D _scale;
	ID3D11ShaderResourceView* _textureRV;

	XMFLOAT4X4 _world;
	GameObject* _parent = nullptr;
	
};

#endif