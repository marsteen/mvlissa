//---------------------------------------------------------------------------
//
// PROJECT : Basic SDL
//
//
// AUTOR   : Martin Steen
//           email: martin@martin-steen.de
//
//
//----------------------------------------------------------------------------

#include <CSDLblurline.h>
#include <CGL_Context.h>

using namespace std;

extern const char* GlobalWindowName;


// ---------------------------------------------------------------------------
//
// KLASSE        : CSDLblurline
// METHODE       : CSDLblurline
//
//
//
// ---------------------------------------------------------------------------

CSDLblurline::CSDLblurline()
{
    mContext = NULL;
}


// ---------------------------------------------------------------------------
//
// KLASSE        : CSDLblurline
// METHODE       : ParseArgVec
//
//
//
// ---------------------------------------------------------------------------

void CSDLblurline::ParseArgVec(const std::vector<std::string>& ArgStr)
{
    //GlobalDebugT("ArgStr.size()=", ArgStr.size(), DBG_MAPS);

    if (ArgStr.size() > 0)
    {
        //mFilename = ArgStr[0];
    }
}


// ---------------------------------------------------------------------------
//
// KLASSE        : I3DF_CImg3dfViewer
// METHODE       : ParseMouseRel
//
//
//
// ---------------------------------------------------------------------------

void CSDLblurline::ParseMouseRel(int xrel, int yrel)
{
    //cout << "xrel=" << xrel << " yrel=" << yrel << endl;

    mContext->MouseMove(xrel, yrel, mLeftMouseButton, mRightMouseButton);

/*
 *  if (mLeftMouseButton)
 *  {
 *  }
 *  else
 *  if (mRightMouseButton)
 *  {
 *  }
 */
}


// ---------------------------------------------------------------------------
//
// KLASSE        : I3DF_CImg3dfViewer
// METHODE       : SetUpDrawing
//
//
//
// ---------------------------------------------------------------------------

void CSDLblurline::SetUpDrawing(float StereoOffset)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //
    // 2D Operationen
    //
}


// ---------------------------------------------------------------------------
//
// KLASSE        : CSDLblurline
// METHODE       : MouseWheel
//
//
//
// ---------------------------------------------------------------------------

void CSDLblurline::MouseWheel(bool up)
{
}


// ---------------------------------------------------------------------------
//
// KLASSE        : CSDLblurline
// METHODE       : GameLoop
//
//
//
// ---------------------------------------------------------------------------

void CSDLblurline::GameLoop()
{
    if (mInitFlag)
    {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDisable(GL_DEPTH_TEST);


        //
        // 2D
        //


        //StartProjectionView();

        //cout << "GameLoop" << endl;



        mContext->Draw2D();


        SDL_GL_SwapWindow(mSdlWindow);
    }
}


// ---------------------------------------------------------------------------
//
// KLASSE        : CSDLblurline
// METHODE       : InitGame
//
//
//
// ---------------------------------------------------------------------------

void CSDLblurline::InitGame()
{
    glewInit();
    mContext = CGL_Context::CreateContext();
    mContext->Init(mXres, mYres);

    //SDL_WM_SetCaption(GlobalWindowName, GlobalWindowName);
}


// ---------------------------------------------------------------------------
//
// KLASSE        : CSDLblurline
// METHODE       : ParseKeys
//
// ---------------------------------------------------------------------------

bool CSDLblurline::ParseKeys(int key, bool down)
{
    bool r = true;

    if (down)
    {
        switch (key)
        {
            case SDLK_ESCAPE:

                r = false; // Programm beenden
                if (mContext != NULL)
                {
                    mContext->Finish();
                }
                break;
        }

        if ((key >= SDLK_a) && (key <= SDLK_z))
        {
            mContext->KeyPress(key - SDLK_a + 'a', down);
        }
    }

    return r;
}


// ---------------------------------------------------------------------------
//
// KLASSE        : CSDLblurline
// METHODE       : SetResolution
//
//
//
// ---------------------------------------------------------------------------

void CSDLblurline::SetResolution(int w, int h)
{
    if (!mInitFlag)
    {
        mInitFlag = true;
    }
}
