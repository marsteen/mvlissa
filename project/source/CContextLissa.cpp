//***************************************************************************
//
//
// @PROJECT  :	Basic SDL
// @VERSION  :	1.0
// @FILENAME :	CContextLissa.cpp
// @DATE     :	8.1.2015
//
// @AUTHOR   :	Martin Steen
// @EMAIL    :	martin@martin-steen.de
//
//
//***************************************************************************

#include <iostream>
#include <fstream>
#include <CGL_Basic.h>
#include <NGlobalLog.h>
#include <CContextLissa.h>
#include <MathDefines.h>
#include <CRandom.h>

#include <GLline/CLineData.h>
#include <GLline/CPointData.h>
#include <GLline/CRingData.h>
#include <GLline/CPointObject.h>
#include <CPlayObject.h>
#include <CFrameBuffer.h>

using namespace std;
using namespace NGlobalLog;


float GlobalAspect = 1.0;
//static CGL_Freetype* Freetype;
static CPlayObject* block;
static CPlayObject racket;
static CPointObject Ball;
static CFrameBuffer* FrameBuffer;
static float LissaWidth = 0.05;



extern void checkGlError(const char* func);

CGL_Context* CGL_Context::CreateContext()
{
    return new CContextLissa;
}


CContextLissa::CContextLissa() : CGL_Context()
{
    mVerSpeed = 2.0f;
    mHorSpeed = 1.0f;
    mResolution = 1;
    mSpeed = 1;
}


//---------------------------------------------------------------------------
//
//
// Klasse:  CContextLissa
// Methode  CalcLissa
//
//
//---------------------------------------------------------------------------

void CContextLissa::CalcLissa(TLinePoints& LissaPoints, float horInit, float verInit, float verSpeed, float horSpeed)
{
    float AngleHor = horInit;
    float AngleVer = verInit;
    float scale = 0.7f;
    int lim = 315 * mResolution;

    for (int i = 0; i < lim; i++)
    {
        CVector2<float> p;
        p.x = sin(AngleVer) * scale;
        p.y = sin(AngleHor) * scale;
        LissaPoints.push_back(p);

        AngleVer += verSpeed * 0.02f / mResolution;
        AngleHor += horSpeed * 0.02f / mResolution;
    }
}


void CContextLissa::KeyPress(int key, bool down)
{
    float w = 1.0f;

    cout << "key=" << key << " down=" << down << endl;
    if (down)
    {
        switch (key)
        {
            case 'r':

                mHorSpeed = 1.0f;
                mVerSpeed = 1.0f;
                mResolution = 1;
                mSpeed = 1;
                break;

            case 'a':

                if (mHorSpeed > 1.0f)
                {
                    mHorSpeed -= w;
                }
                break;

            case 'd':

                mHorSpeed += w;
                break;

            case 's':

                if (mVerSpeed > 1.0f)
                {
                    mVerSpeed -= w;
                }
                break;

            case 'w':

                mVerSpeed += w;
                break;

            case 'o':

                if (mResolution > 1)
                {
                    mResolution -= 1;
                }
                break;

            case 'p':

                mResolution++;
                break;

            case 'u':

                if (mSpeed > 1)
                {
                    mSpeed -= 1;
                }
                break;

            case 'v':

                LissaWidth -= 0.01;
                cout << "LissaWidth=" << LissaWidth << endl;
                break;

            case 'b':

                LissaWidth += 0.01;
                cout << "LissaWidth=" << LissaWidth << endl;
                break;

            case 'i':

                mSpeed++;
                break;
        }
    }
}


//---------------------------------------------------------------------------
//
//
// Klasse:  CContextLissa
// Methode  Init
//
//
//---------------------------------------------------------------------------


bool CContextLissa::Init(int w, int h)
{
    CGL_Context::Init(w, h);

    mColorShader = new CGL_Shader_Color;
    mColorShader->InitShader();

    mBlurlineShader = new CGL_Shader_Blurline;
    mBlurlineShader->InitShader();

    mNoiseShader = new CGL_Shader_Noise;
    mNoiseShader->InitShader();


    mTextureShader = new CGL_Shader_Texture;
    mTextureShader->InitShader();

    cout << "Width=" << mWidth << " Height=" << mHeight << endl;

    return true;
}


//---------------------------------------------------------------------------
//
//
// Klasse:  CContextLissa
// Methode  MouseMove
//
//
//---------------------------------------------------------------------------

void CContextLissa::MouseMove(int xrel, int yrel, bool lb, bool rb)
{
    if (fabs(xrel) < 100)
    {
        racket.mSpeed = float(xrel) / 500.0f;
        racket.mPos.x += racket.mSpeed;
    }
}


#define LINE_W    0.04f

static const float ColorGreen[] = { 1.0f, 1.0f, 1.0f, 1.0f };   // 2

//---------------------------------------------------------------------------
//
//
// Klasse:  CContextLissa
// Methode  Draw2D
//
//
//---------------------------------------------------------------------------

void CContextLissa::Draw2D()
{
    //
    // Farbiges Quadrat zeichnen
    //

    static float horInit;
    static float verInit;

    //cout << "Draw2D() START" << endl;
    static const float ColorWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //
    static const float ColorBlue[] = { 0.5f, 0.5f, 0.5f, 1.0f };    //
    static const float ColorGrey[] =
    {
        0.1f, 0.1f, 0.1f, 1.0f, // links unten
        0.1f, 0.1f, 0.1f, 1.0f, // rechts unten
        0.1f, 0.1f, 0.1f, 1.0f, // rechts oben
        0.1f, 0.1f, 0.1f, 1.0f, // links oben
    };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    mColorShader->UseProgram();
    mColorShader->SetUniformFloat("uAspect", mAspect);
    //CGL_Basic::DrawQuad(mColorShader, -1.0, -1.0f,  1.0f, 1.0f, ColorGrey);

    mBlurlineShader->UseProgram();
    mBlurlineShader->SetUniformFloat("uAspect", mAspect);
    checkGlError("SetUniformFloat");

    GlobalAspect = mAspect;


    /*
     * mBlurlineShader->SetObjAngle(a2);
     * mBlurlineShader->SetObjPos(p2.x, p2.y);
     * mBlurlineShader->SetObjOrigin(org.x, org.y);
     */



#define POINTS    5

    static CLineData LineData[4];
    static CRingData RingData[4];

    glDisable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);



    TLinePoints LissaPoints;
    CalcLissa(LissaPoints, horInit, verInit, mHorSpeed, mVerSpeed);
    CLineStrip::Draw(mBlurlineShader, LissaPoints, LissaWidth, ColorWhite);
    horInit += 0.02 * mSpeed;
    verInit += 0.02 * mSpeed;

    /*
     * LineData[0].Draw(mBlurlineShader, -1.0f, -1.0f,  1.0f,-1.0f, LINE_W, ColorGreen);
     * LineData[1].Draw(mBlurlineShader,  1.0f, -1.0f,  1.0f, 1.0f, LINE_W, ColorGreen);
     * LineData[2].Draw(mBlurlineShader,  1.0f,  1.0f, -1.0f, 1.0f, LINE_W, ColorGreen);
     * LineData[3].Draw(mBlurlineShader, -1.0f,  1.0f, -1.0f,-1.0f, LINE_W, ColorGreen);
     */

    glUseProgram(0);
    //cout << "Draw2D() END" << endl;
}
