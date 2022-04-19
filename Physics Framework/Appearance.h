#pragma once
#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Debug.h"
#include "Vector3d.h"
#include "Structures.h"

class Appearance
{
public:
	Appearance(Geometry geometry, Material material);
	~Appearance();
	Geometry GetGeometryData() const { return _geometry; }

	Material GetMaterial() const { return _material; }

	void Draw(ID3D11DeviceContext* pImmediateContext);
	ID3D11ShaderResourceView* GetResourceView() const{ return _textureRV; }
	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

private:
	Geometry _geometry;
	Material _material;
	ID3D11ShaderResourceView* _textureRV;
};

