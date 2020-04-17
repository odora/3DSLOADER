// TriObject.h: interface for the CTriObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIOBJECT_H__922F85A8_F87E_4F9B_B49D_5B1175163166__INCLUDED_)
#define AFX_TRIOBJECT_H__922F85A8_F87E_4F9B_B49D_5B1175163166__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "glStructures.h"

class CTriObject  
{
public:
	CTriObject();
	virtual ~CTriObject();

	void setId(int _id);
	void drawGL();
	void applyNormals();

	//基本操作
	void setX( float* _x, int num )		{x = _x; numvertices = num;};
	void setY( float* _y, int num )		{y = _y; numvertices = num;};
	void setZ( float* _z, int num )		{z = _z; numvertices = num;};
	void getX( float*& _x, int& num )	{_x = x; num = numvertices;};
	void getY( float*& _y, int& num )	{_y = y; num = numvertices;};
	void getZ( float*& _z, int& num )	{_z = z; num = numvertices;};

	void setXN( float* _nx, int num )	{nx = _nx; numnormals = num;};
	void setYN( float* _ny, int num )	{ny = _ny; numnormals = num;};
	void setZN( float* _nz, int num )	{nz = _nz; numnormals = num;};
	void getXN( float*& _nx, int& num ) {_nx = nx; num = numnormals;};
	void getYN( float*& _ny, int& num ) {_ny = ny; num = numnormals;};
	void getZN( float*& _nz, int& num ) {_nz = nz; num = numnormals;};
	
	void setFaces( int* _faces, int num)	{faces = _faces; numfaces = num; matfaces = new int[num/3];};
	void getFaces( int*& _faces, int& num)	{_faces = faces; num = numfaces;};

	int	 addMaterial( tMaterial* _material);
	void addMaterialFace(int entry, int index) {matfaces[entry] = index; nummatfacesapplied++; if(nummatfacesapplied < numfaces/3) materialsapplied = FALSE; else materialsapplied = TRUE; };
	
	void setName(char * _name) {name = new char[strlen(_name)]; strcpy(name,_name);};
	void getName(char *& _name) {_name = name;};

	void setPivotPoint(tVector* _pivot) {pivot[0] = _pivot->x; pivot[1] = _pivot->y; pivot[2] = _pivot->z;}
	void getPivotPoint(tVector* _pivot) {_pivot->x = pivot[0]; _pivot->y = pivot[1]; _pivot->z = pivot[2];}


private:
	void CalcNormal(int entry , float out[3]);
	void ReduceToUnit(float vector[3]);
	BOOL isDataAlive();
	BOOL normalapplied;
	BOOL materialsapplied;

	int			id;
	int			i;
	float		value, valuepos;
	//基本的材质成员变量
	float*		x;
	float*		y;
	float*		z;
	int			numvertices;
	float*		nx;
	float*		ny;
	float*		nz;
	int			numnormals;
	int*		faces;
	int			numfaces;
	tMaterial*	materials;
	int			nummaterials;
	int*		matfaces;
	int			nummatfacesapplied;
	char*		name;
	float		pivot[3];
	float		pivotrot[4];

};

#endif // !defined(AFX_TRIOBJECT_H__922F85A8_F87E_4F9B_B49D_5B1175163166__INCLUDED_)
