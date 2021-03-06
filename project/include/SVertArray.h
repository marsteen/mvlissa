//***************************************************************************
//
//
// @PROJECT  :	Basic SDL
// @VERSION  :	1.0
// @FILENAME :	SVertArray.h
// @DATE     :	8.1.2015
//
// @AUTHOR   :	Martin Steen
// @EMAIL    :	martin@martin-steen.de
//
//
//***************************************************************************

#ifndef SVertArray_h
#define SVertArray_h

//---------------------------------------------------------------------------
//
// Klasse:    
// Methode:   
//
//
//---------------------------------------------------------------------------

#include <cstdio>
#include <CVector2T.h>
#include <CVector3T.h>

struct SVertArray
{
  SVertArray()
  {
    mVert   = NULL;
    mNorm   = NULL;
    mText   = NULL;
    mVindex = 0;
    mNindex = 0;
    mTindex = 0;
    mCount  = 0;
  }
  
  ~SVertArray()
  {		
    delete[] mVert;
    delete[] mNorm;
    delete[] mText;
  }
	void MakeVerts(int count)
  {
    mVert = new CVector3<float>[count];
    mVindex = 0;
  }
	void MakeNorms(int count)
  {
    mNorm = new CVector3<float>[count];
    mNindex = 0;
  }

	void MakeTexts(int count)
  {
    mText = new CVector2<float>[count];
    mTindex = 0;
  }


  void AddVert(const CVector3<float>& vert)
  {
    mVert[mVindex++] = vert;
  }
  void AddNorm(const CVector3<float>& norm)
  {
    mNorm[mNindex++] = norm;
  }
  void AddText(const CVector2<float>& norm)
  {
    mText[mTindex++] = norm;
  }
  
  unsigned int mCount;
  unsigned int mVindex;
  unsigned int mNindex;
  unsigned int mTindex;
  
  CVector3<float>* mVert;    // Vertex-Array
  CVector3<float>* mNorm;    // Normal-Array
  CVector2<float>* mText;    // Texture-Array
};

//
//
//

struct SVertArray2D
{
  SVertArray2D()
  {
    mVert   = NULL;
    mText   = NULL;
    mVindex = 0;
    mTindex = 0;
    mCount  = 0;
  }
  
  ~SVertArray2D()
  {		
    delete[] mVert;
    delete[] mText;
  }
	void MakeVerts(int count)
  {
    mVert = new CVector2<float>[count];
    mVindex = 0;
  }
	void MakeTexts(int count)
  {
    mText = new CVector2<float>[count];
    mTindex = 0;
  }


  void AddVert(const CVector2<float>& vert)
  {
    mVert[mVindex++] = vert;
  }
  void AddText(const CVector2<float>& norm)
  {
    mText[mTindex++] = norm;
  }
  
  unsigned int mCount;
  unsigned int mVindex;
  unsigned int mTindex;
  
  CVector2<float>* mVert;    // Vertex-Array  
  CVector2<float>* mText;    // Texture-Array
};



#endif
