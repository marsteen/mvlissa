#include <CGL_Basic.h>
#include <GLline/CLineData.h>
#include <GLline/StaticLineHelp.hpp>
#include <iostream>

//#define LINE_W (1.0f / 25.0f)
using namespace std;


//---------------------------------------------------------------------------
//
//
// Klasse:  CContextLissa
// Methode  DrawLine
//
//
//---------------------------------------------------------------------------


static void InitLine(
    CGL_Shader_Blurline* shader,
    float x1, float y1,
    float x2, float y2,
    float LineWidth,
    const float* color,
    float* LineAngle,
    SVertArray2D* ar)
{
    CVector2<float> v1(x1, y1);
    CVector2<float> v2(x2, y2);
    float dx = x1 - x2;
    float dy = y1 - y2;

    *LineAngle = atan2(dy, dx) - DEG_TO_RAD(90.0f);

    //*LineAngle = 0.0f;
    //cout << "LineAngle=" << RAD_TO_DEG(*LineAngle) << endl;

    //cout << "w=" << w << endl;

    float len = v1.Abstand(&v2);

    //cout << "len=" << len << endl;

    //shader->SetAngle(mLineAngle);
    //shader->SetPos(x1, y1);


    const float textcoordsLeft[] =
    {
        1.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 1.0f
    };
    const float textcoordsRight[] =
    {
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 0.0f
    };


    float cx1 = 0.0f;
    float cx2 = 0.0f + LineWidth;
    float cy1 = 0.0f;
    float cy2 = 0.0f + len;


    //shader->SetColor(color);



    glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //CGL_Basic::DrawQuad(mBlurlineShader, -0.5f, -0.5f, 0.5f, 0.5f, Colors);
    //CGL_Basic::DrawLine(this, -0.5f, -0.5f, 0.5f, 0.5f);



    {
        CGL_Basic::CreateQuadTexCoords(0.0f, 0.0f, LineWidth, len, textcoordsLeft, ar[0]);
        CGL_Basic::CreateQuadTexCoords(-LineWidth, 0.0f, 0.0f, len, textcoordsRight, ar[1]);

        /*
         * glEnableVertexAttribArray(shader->VertAttrib());
         * glEnableVertexAttribArray(shader->TextAttrib());
         *
         * CGL_Basic::DrawQuadTexCoords(shader, ar[0]);
         * CGL_Basic::DrawQuadTexCoords(shader, ar[1]);
         *
         *
         * glDisableVertexAttribArray(shader->VertAttrib());
         * glDisableVertexAttribArray(shader->TextAttrib());
         */
    }


    //CGL_Basic::DrawQuadTexCoords(shader, 0.0f, 0.0f, LINE_W, len,  textcoordsLeft);

    //CGL_Basic::DrawQuadTexCoords(shader, -LINE_W, 0.0f, 0.0f, len, textcoordsRight);

#if 1
    {
        // 1. Kappe
        CVector2<float> org(0.0f, 0.0f);
        std::vector<CVector2<float> > vec;
        vec.push_back(org);
        GetCirclePoints<float>(180.0f, 360.0f, LineWidth, 16, 0.0f, 0.0f, vec);
        CGL_Basic::CreateTrifan(vec, ar[2]);
        //CGL_Basic::DrawTrifan(shader, ar);
    }

    {
        // 2. Kappe
        CVector2<float> org(0.0f, len);
        std::vector<CVector2<float> > vec;
        vec.push_back(org);
        GetCirclePoints<float>(0.0, 180.0f, LineWidth, 16, 0.0f, len, vec);
        CGL_Basic::CreateTrifan(vec, ar[3]);
        //CGL_Basic::DrawTrifan(shader, ar);
    }
#endif
}


void CLineData::Draw(
    CGL_Shader_Blurline* shader,
    float x1, float y1,
    float x2, float y2,
    float LineWidth,
    const float* color)
{
    if (!mInit)
    {
        mP1.Set(x1, y1);
        mP1.Set(x2, y2);
        mColor = color;

        InitLine(shader, x1, y1, x2, y2, LineWidth, color, &mLineAngle, mAr);
        mInit = true;
    }
    DrawLineData(shader);
}


void CLineData::DrawLineData(CGL_Shader_Blurline* shader)
{
    shader->SetAngle(mLineAngle);
    shader->SetPos(mP1.x, mP1.y);
    shader->SetColor(mColor);

    glEnableVertexAttribArray(shader->VertAttrib());
    glEnableVertexAttribArray(shader->TextAttrib());

    CGL_Basic::DrawQuadTexCoords(shader, mAr[0]);
    CGL_Basic::DrawQuadTexCoords(shader, mAr[1]);
    CGL_Basic::DrawTrifan(shader, mAr[2]);
    CGL_Basic::DrawTrifan(shader, mAr[3]);


    glDisableVertexAttribArray(shader->VertAttrib());
    glDisableVertexAttribArray(shader->TextAttrib());
}
