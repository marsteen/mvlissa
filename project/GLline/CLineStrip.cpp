
#include <CLineData.h>
#include <CLineStrip.h>



void CLineStrip::Draw(CGL_Shader_Blurline* shader, const TLinePoints& points, float lw, const float* color)
{
    for (int i = 1; i < points.size(); i++)
    {
        CLineData LineData;
        LineData.Draw(shader, points[i-1].x, points[i-1].y, points[i].x, points[i].y, lw, color);
    }
}
