#include <windows.h>

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

typedef int HInputContext;

struct InputEvent_t
{
	int m_nType;				// Type of the event (see InputEventType_t)
	int m_nTick;				// Tick on which the event occurred
	int m_nData;				// Generic 32-bit data, what it contains depends on the event
	int m_nData2;				// Generic 32-bit data, what it contains depends on the event
	int m_nData3;				// Generic 32-bit data, what it contains depends on the event
};

enum
{
	MAX_JOYSTICKS = 1,
	MOUSE_BUTTON_COUNT = 5,
};

enum JoystickAxis_t
{
	JOY_AXIS_X = 0,
	JOY_AXIS_Y,
	JOY_AXIS_Z,
	JOY_AXIS_R,
	JOY_AXIS_U,
	JOY_AXIS_V,
	MAX_JOYSTICK_AXES,
};

enum
{
	JOYSTICK_MAX_BUTTON_COUNT = 32,
	JOYSTICK_POV_BUTTON_COUNT = 4,
	JOYSTICK_AXIS_BUTTON_COUNT = MAX_JOYSTICK_AXES * 2,
};

enum MouseCodeState_t
{
	BUTTON_RELEASED = 0,
	BUTTON_PRESSED,
	BUTTON_DOUBLECLICKED,
};

#define JOYSTICK_BUTTON_INTERNAL( _joystick, _button ) ( JOYSTICK_FIRST_BUTTON + ((_joystick) * JOYSTICK_MAX_BUTTON_COUNT) + (_button) )
#define JOYSTICK_POV_BUTTON_INTERNAL( _joystick, _button ) ( JOYSTICK_FIRST_POV_BUTTON + ((_joystick) * JOYSTICK_POV_BUTTON_COUNT) + (_button) )
#define JOYSTICK_AXIS_BUTTON_INTERNAL( _joystick, _button ) ( JOYSTICK_FIRST_AXIS_BUTTON + ((_joystick) * JOYSTICK_AXIS_BUTTON_COUNT) + (_button) )

#define JOYSTICK_BUTTON( _joystick, _button ) ( (ButtonCode_t)JOYSTICK_BUTTON_INTERNAL( _joystick, _button ) )
#define JOYSTICK_POV_BUTTON( _joystick, _button ) ( (ButtonCode_t)JOYSTICK_POV_BUTTON_INTERNAL( _joystick, _button ) )
#define JOYSTICK_AXIS_BUTTON( _joystick, _button ) ( (ButtonCode_t)JOYSTICK_AXIS_BUTTON_INTERNAL( _joystick, _button ) )

enum ButtonCode_t
{
	BUTTON_CODE_INVALID = -1,
	BUTTON_CODE_NONE = 0,

	KEY_FIRST = 0,

	KEY_NONE = KEY_FIRST,
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_PAD_0,
	KEY_PAD_1,
	KEY_PAD_2,
	KEY_PAD_3,
	KEY_PAD_4,
	KEY_PAD_5,
	KEY_PAD_6,
	KEY_PAD_7,
	KEY_PAD_8,
	KEY_PAD_9,
	KEY_PAD_DIVIDE,
	KEY_PAD_MULTIPLY,
	KEY_PAD_MINUS,
	KEY_PAD_PLUS,
	KEY_PAD_ENTER,
	KEY_PAD_DECIMAL,
	KEY_LBRACKET,
	KEY_RBRACKET,
	KEY_SEMICOLON,
	KEY_APOSTROPHE,
	KEY_BACKQUOTE,
	KEY_COMMA,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_BACKSLASH,
	KEY_MINUS,
	KEY_EQUAL,
	KEY_ENTER,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_TAB,
	KEY_CAPSLOCK,
	KEY_NUMLOCK,
	KEY_ESCAPE,
	KEY_SCROLLLOCK,
	KEY_INSERT,
	KEY_DELETE,
	KEY_HOME,
	KEY_END,
	KEY_PAGEUP,
	KEY_PAGEDOWN,
	KEY_BREAK,
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_LALT,
	KEY_RALT,
	KEY_LCONTROL,
	KEY_RCONTROL,
	KEY_LWIN,
	KEY_RWIN,
	KEY_APP,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_CAPSLOCKTOGGLE,
	KEY_NUMLOCKTOGGLE,
	KEY_SCROLLLOCKTOGGLE,

	KEY_LAST = KEY_SCROLLLOCKTOGGLE,
	KEY_COUNT = KEY_LAST - KEY_FIRST + 1,

	// Mouse
	MOUSE_FIRST = KEY_LAST + 1,

	MOUSE_LEFT = MOUSE_FIRST,
	MOUSE_RIGHT,
	MOUSE_MIDDLE,
	MOUSE_4,
	MOUSE_5,
	MOUSE_WHEEL_UP,		// A fake button which is 'pressed' and 'released' when the wheel is moved up 
	MOUSE_WHEEL_DOWN,	// A fake button which is 'pressed' and 'released' when the wheel is moved down

	MOUSE_LAST = MOUSE_WHEEL_DOWN,
	MOUSE_COUNT = MOUSE_LAST - MOUSE_FIRST + 1,

	// Joystick
	JOYSTICK_FIRST = MOUSE_LAST + 1,

	JOYSTICK_FIRST_BUTTON = JOYSTICK_FIRST,
	JOYSTICK_LAST_BUTTON = JOYSTICK_BUTTON_INTERNAL(MAX_JOYSTICKS - 1, JOYSTICK_MAX_BUTTON_COUNT - 1),
	JOYSTICK_FIRST_POV_BUTTON,
	JOYSTICK_LAST_POV_BUTTON = JOYSTICK_POV_BUTTON_INTERNAL(MAX_JOYSTICKS - 1, JOYSTICK_POV_BUTTON_COUNT - 1),
	JOYSTICK_FIRST_AXIS_BUTTON,
	JOYSTICK_LAST_AXIS_BUTTON = JOYSTICK_AXIS_BUTTON_INTERNAL(MAX_JOYSTICKS - 1, JOYSTICK_AXIS_BUTTON_COUNT - 1),

	JOYSTICK_LAST = JOYSTICK_LAST_AXIS_BUTTON,

	BUTTON_CODE_LAST,
	BUTTON_CODE_COUNT = BUTTON_CODE_LAST - KEY_FIRST + 1,

	// Helpers for XBox 360
	KEY_XBUTTON_UP = JOYSTICK_FIRST_POV_BUTTON,	// POV buttons
	KEY_XBUTTON_RIGHT,
	KEY_XBUTTON_DOWN,
	KEY_XBUTTON_LEFT,

	KEY_XBUTTON_A = JOYSTICK_FIRST_BUTTON,		// Buttons
	KEY_XBUTTON_B,
	KEY_XBUTTON_X,
	KEY_XBUTTON_Y,
	KEY_XBUTTON_LEFT_SHOULDER,
	KEY_XBUTTON_RIGHT_SHOULDER,
	KEY_XBUTTON_BACK,
	KEY_XBUTTON_START,
	KEY_XBUTTON_STICK1,
	KEY_XBUTTON_STICK2,

	KEY_XSTICK1_RIGHT = JOYSTICK_FIRST_AXIS_BUTTON,	// XAXIS POSITIVE
	KEY_XSTICK1_LEFT,							// XAXIS NEGATIVE
	KEY_XSTICK1_DOWN,							// YAXIS POSITIVE
	KEY_XSTICK1_UP,								// YAXIS NEGATIVE
	KEY_XBUTTON_LTRIGGER,						// ZAXIS POSITIVE
	KEY_XBUTTON_RTRIGGER,						// ZAXIS NEGATIVE
	KEY_XSTICK2_RIGHT,							// UAXIS POSITIVE
	KEY_XSTICK2_LEFT,							// UAXIS NEGATIVE
	KEY_XSTICK2_DOWN,							// VAXIS POSITIVE
	KEY_XSTICK2_UP,								// VAXIS NEGATIVE
};

namespace vgui
{
	// handle to an internal vgui panel
	// this is the only handle to a panel that is valid across dll boundaries
	typedef unsigned int VPANEL;

	// handles to vgui objects
	// NULL values signify an invalid value
	typedef unsigned long HScheme;
	typedef unsigned long HTexture;
	typedef unsigned long HCursor;
	typedef unsigned long HPanel;
	typedef ButtonCode_t MouseCode;
	typedef ButtonCode_t KeyCode;
	const HPanel INVALID_PANEL = 0xffffffff;
	typedef unsigned long HFont;
	const HFont INVALID_FONT = 0; // the value of an invalid font handle
}

using namespace vgui;

typedef float vec_t;

class Vector2D					
{
public:
	vec_t x, y;
};

struct Vertex_t
{
	Vector2D	m_Position;
	Vector2D	m_TexCoord;
};

class Color
{
public:
	// constructors
	Color()
	{
		*((int *)this) = 0;
	}
	Color(int r,int g,int b)
	{
		SetColor(r, g, b, 0);
	}
	Color(int r,int g,int b,int a)
	{
		SetColor(r, g, b, a);
	}
	
	// set the color
	// r - red component (0-255)
	// g - green component (0-255)
	// b - blue component (0-255)
	// a - alpha component, controls transparency (0 - transparent, 255 - opaque);
	void SetColor(int r, int g, int b, int a = 0)
	{
		_color[0] = (unsigned char)r;
		_color[1] = (unsigned char)g;
		_color[2] = (unsigned char)b;
		_color[3] = (unsigned char)a;
	}

	void GetColor(int &r, int &g, int &b, int &a) const
	{
		r = _color[0];
		g = _color[1];
		b = _color[2];
		a = _color[3];
	}

	void SetRawColor( int color32 )
	{
		*((int *)this) = color32;
	}

	int GetRawColor() const
	{
		return *((int *)this);
	}

	inline int r() const	{ return _color[0]; }
	inline int g() const	{ return _color[1]; }
	inline int b() const	{ return _color[2]; }
	inline int a() const	{ return _color[3]; }
	
	unsigned char &operator[](int index)
	{
		return _color[index];
	}

	const unsigned char &operator[](int index) const
	{
		return _color[index];
	}

	bool operator == (const Color &rhs) const
	{
		return ( *((int *)this) == *((int *)&rhs) );
	}

	bool operator != (const Color &rhs) const
	{
		return !(operator==(rhs));
	}

	Color &operator=( const Color &rhs )
	{
		SetRawColor( rhs.GetRawColor() );
		return *this;
	}

private:
	unsigned char _color[4];
};

struct IntRect
{
	int x0;
	int y0;
	int x1;
	int y1;
};

enum FontDrawType_t
{
	// Use the "additive" value from the scheme file
	FONT_DRAW_DEFAULT = 0,

	// Overrides
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,

	FONT_DRAW_TYPE_COUNT = 2,
};

struct CharRenderInfo
{
	// In:
	FontDrawType_t	drawType;
	wchar_t			ch;

	// Out
	bool			valid;

	// In/Out (true by default)
	bool			shouldclip;
	// Text pos
	int				x, y;
	// Top left and bottom right
	Vertex_t		verts[ 2 ];
	int				textureId;
	int				abcA;
	int				abcB;
	int				abcC;
	int				fontTall;
	vgui::HFont		currentFont;
};

struct ISurface
{
	void(__stdcall *Unknown000)();																	//0000
	void(__stdcall *Unknown001)();  																//0004
	void(__stdcall *Unknown002)();								        							//0008
	void(__stdcall *Unknown003)();																	//000C
	void(__stdcall *Unknown004)();																	//0010
	void(__stdcall *Unknown005)();																	//0014
	void(__stdcall *Unknown006)();																	//0018
	void(__stdcall *Unknown007)();											                		//001C
	void(__stdcall *Unknown008)();													        		//0020
	void(__stdcall *Unknown009)();	 			                    								//0024
	void(__stdcall *PushMakeCurrent)(VPANEL panel, bool useInsets);									//0028
	void(__stdcall *PopMakeCurrent)(VPANEL panel);													//002C
	void(__stdcall *DrawSetColor001)(Color col); 									                //0030
	void(__stdcall *DrawSetColor002)(int r, int g, int b, int a);									//0034
	void(__stdcall *DrawFilledRect)(int x0, int y0, int x1, int y1);								//0038
	void(__stdcall *DrawFilledRectArray)(IntRect *pRects, int numRects);							//003C
	void(__stdcall *DrawOutlinedRect)(int x0, int y0, int x1, int y1);								//0040
	void(__stdcall *DrawLine)(int x0, int y0, int x1, int y1);										//0044
	void(__stdcall *DrawPolyLine)(int *px, int *py, int numPoints);									//0048
	void(__stdcall *DrawSetTextFont)(HFont font);													//004C
	void(__stdcall *DrawSetTextColor001)(int col); 								                    //0050
	void(__stdcall *DrawSetTextColor002)(int r, int g, int b, int a);								//0054
	void(__stdcall *DrawSetTextPos)(int x, int y);													//0058
	void(__stdcall *DrawGetTextPos)(int& x, int& y);												//005C
	void(__stdcall *DrawPrintText)(const wchar_t *text, int textLen, FontDrawType_t drawType);		//0060
	void(__stdcall *DrawUnicodeChar)(wchar_t wch, FontDrawType_t drawType);							//0064
	void(__stdcall *DrawUnicodeString)(wchar_t *pString, int len);									//0068
	void(__stdcall *Unknown0001)();																	//006C
	void(__stdcall *Unknown0002)();																	//0070
	void(__stdcall *Unknown0003)();																	//0074
	void(__stdcall *Unknown0004)();																	//0078
	void(__stdcall *Unknown0005)();																	//007C
	void(__stdcall *Unknown0006)();																	//0080
	void(__stdcall *Unknown0007)();																	//0084
	void(__stdcall *Unknown0008)();																	//0088
	void(__stdcall *Unknown0009)();																	//008C
	void(__stdcall *Unknown0010)();																	//0090
	void(__stdcall *Unknown0011)();																	//0094
	void(__stdcall*UnknowDraw2)(int x0, int y0, int x1, int y1);		        					//0098
	void(__stdcall *Unknown0013)();																	//009C
	void(__stdcall*UnknowDraw1)(int x0, int y0, int x1, int y1);									//00A0
	void(__stdcall *Unknown0015)();                     							    	        //00A4
	void(__stdcall *Unknown0016)();																	//00A8
	void(__stdcall *Unknown0017)();																	//00AC
	void(__stdcall *Unknown0018)();																	//00B0
	void(__stdcall *Unknown0019)();																	//00B4
	void(__stdcall *Unknown0020)();																	//00B8
	void(__stdcall *Unknown0021)();																	//00BC
	void(__stdcall *Unknown0022)();																	//00C0
	void(__stdcall *Unknown0023)();																	//00C4
	void(__stdcall *Unknown0024)();																	//00C8
	void(__stdcall *Unknown0025)();																	//00CC
	void(__stdcall *Unknown0026)();																	//00D0
	void(__stdcall *Unknown0027)();																	//00D4
	void(__stdcall *Unknown0028)();																	//00D8
	void(__stdcall *Unknown0029)();																	//00DC
	void(__stdcall *Unknown0030)();																	//00E0
	void(__stdcall *Unknown0031)();																	//00E4
	void(__stdcall *Unknown0032)();																	//00E8
	void(__stdcall *Unknown0033)();																	//00EC
	void(__stdcall *Unknown0034)();																	//00F0
	void(__stdcall *Unknown0035)();																	//00F4
	void(__stdcall *Unknown0036)();																	//00F8
	void(__stdcall *Unknown0037)();																	//00FC
	void(__stdcall *Unknown0038)();																	//0100
	void(__stdcall *Unknown0039)();																	//0104
	void(__stdcall *Unknown0040)();																	//0108
	bool(__stdcall *SupportsFeature)(int feature);													//010C
	void(__stdcall *RestrictPaintToSinglePanel)(VPANEL panel);										//0110
	void(__stdcall *Unknown0041)();																	//0114
	void(__stdcall *Unknown0042)();																	//0118
	void(__stdcall *Unknown0043)();																	//011C
	void(__stdcall *Unknown0044)();																	//0120
	void(__stdcall *Unknown0045)();																	//0124
	void(__stdcall *Unknown0046)();																	//0128
	void(__stdcall *Unknown0047)();																	//012C
	HFont(__stdcall *CreateFont)();																	//0130
	bool(__stdcall *SetFontGlyphSet)(HFont font, const char *windowsFontName,
		int tall, int weight, int blur, int scanlines, int flags);										//0130
	bool(__stdcall *AddCustomFontFile)(const char *fontFileName);										//0134
	void(__stdcall *Unknown0048)();																	//0138
	void(__stdcall *Unknown0049)();																	//013C
	void(__stdcall *Unknown0050)();																	//0140
	void(__stdcall *Unknown0051)();																	//0144
	void(__stdcall *Unknown0052)();																	//0148
	void(__stdcall *Unknown0053)();																	//014C
	void(__stdcall *Unknown0054)();																	//0150
	void(__stdcall *Unknown0055)();																	//0154
	void(__stdcall *Unknown0056)();																	//0158
	void(__stdcall *Unknown0057)();																	//015C
	void(__stdcall *Unknown0058)();																	//0160
	void(__stdcall *Unknown0059)();																	//0164
	void(__stdcall *PaintTraverse)(VPANEL panel);														//0168
	void(__stdcall *Unknown0060)();																	//016C
	void(__stdcall *Unknown0061)();																	//0170
	void(__stdcall *Unknown0062)();																	//0174
	void(__stdcall *Unknown0063)();																	//0178
	void(__stdcall *Unknown0064)();																	//017C
	void(__stdcall *Unknown0065)();																	//0180
	void(__stdcall *Unknown0066)();																	//0184
	void(__stdcall *Unknown0067)();																	//0188
	void(__stdcall *Unknown0068)();																	//018C
	void(__stdcall *GetProportionalBase)(int &width, int &height);									//0190
	void(__stdcall *CalculateMouseVisible)();															//0194
	bool(__stdcall *NeedKBInput)();																	//0198
	bool(__stdcall *HasCursorPosFunctions)();															//019C
	void(__stdcall *SurfaceGetCursorPos)(int &x, int &y);												//01A0
	void(__stdcall *SurfaceSetCursorPos)(int x, int y);												//01A4
	void(__stdcall *DrawTexturedLine)(const Vertex_t &a, const Vertex_t &b);						//01A8
	void(__stdcall *DrawOutlinedCircle)(int x, int y, int radius, int segments);					//01AC
	void(__stdcall *DrawTexturedPolyLine)(const Vertex_t *p, int n);								//01B0
	void(__stdcall *DrawTexturedSubRect)(int x0, int y0, int x1, int y1,
		float texs0, float text0, float texs1, float text1);										//01B4
	void(__stdcall *DrawTexturedPolygon)(int n, Vertex_t *pVertices);								//01B8
	const wchar_t* (__stdcall *GetTitle)(VPANEL panel);												//01BC
	bool(__stdcall *IsCursorLocked)(void);															//01C0
	void(__stdcall *SetWorkspaceInsets)(int left, int top, int right, int bottom);					//01C4
	bool(__stdcall *DrawGetUnicodeCharRenderInfo)(wchar_t ch, CharRenderInfo& info);				//01C8
	void(__stdcall *DrawRenderCharFromInfo)(const CharRenderInfo& info);							//01CC
	void(__stdcall *DrawSetAlphaMultiplier)(float alpha /* [0..1] */);								//01D0
	float(__stdcall *DrawGetAlphaMultiplier)();														//01D4
	void(__stdcall *SetAllowHTMLJavaScript)(bool state);											//01D8
	void(__stdcall *OnScreenSizeChanged)(int nOldWidth, int nOldHeight);							//01DC
	void(__stdcall *Unknown0069)();																	//01E0
	void(__stdcall *Unknown0070)();																	//01E4
	void(__stdcall *PaintTraverseEx)(VPANEL panel, bool paintPopups);								//01E8
};

class ISurface039
{
public:

	virtual void Unknown000() = 0;																	//0000
	virtual void Unknown001() = 0;  																//0004
	virtual void Unknown002() = 0;								        							//0008
	virtual void Unknown003() = 0;																	//000C
	virtual void Unknown004() = 0;																	//0010
	virtual void Unknown005() = 0;																	//0014
	virtual void Unknown006() = 0;																	//0018
	virtual void Unknown007() = 0;											                		//001C
	virtual void Unknown008() = 0;													        		//0020
	virtual void Unknown009() = 0;	 			                    								//0024
	virtual void PushMakeCurrent(VPANEL panel, bool useInsets) = 0;									//0028
	virtual void PopMakeCurrent(VPANEL panel) = 0;													//002C
	virtual void DrawSetColor001(Color col) = 0; 									                //0030
	virtual void DrawSetColor002(int r, int g, int b, int a) = 0;									//0034
	virtual void DrawFilledRect(int x0, int y0, int x1, int y1) = 0;								//0038
	virtual void DrawFilledRectArray(IntRect *pRects, int numRects) = 0;							//003C
	virtual void DrawOutlinedRect(int x0, int y0, int x1, int y1) = 0;								//0040
	virtual void DrawLine(int x0, int y0, int x1, int y1) = 0;										//0044
	virtual void DrawPolyLine(int *px, int *py, int numPoints) = 0;									//0048
	virtual void DrawSetTextFont(HFont font) = 0;													//004C
	virtual void DrawSetTextColor001(int col) = 0; 								                    //0050
	virtual void DrawSetTextColor002(int r, int g, int b, int a) = 0;								//0054
	virtual void DrawSetTextPos(int x, int y) = 0;													//0058
	virtual void DrawGetTextPos(int& x, int& y) = 0;												//005C
	virtual void DrawPrintText(const wchar_t *text, int textLen, FontDrawType_t drawType) = 0;		//0060
	virtual void DrawUnicodeChar(wchar_t wch, FontDrawType_t drawType) = 0;							//0064
	virtual void DrawUnicodeString(wchar_t *pString, int len) = 0;									//0068
	virtual void Unknown010() = 0;																	//006C
	virtual void Unknown011() = 0;  																//0070
	virtual void Unknown012() = 0;								        							//0074
	virtual void Unknown013() = 0;																	//0078
	virtual void Unknown014() = 0;																	//007C
	virtual void Unknown015() = 0;																	//0080
	virtual void Unknown016() = 0;																	//0084
	virtual void Unknown017() = 0;											                		//0088
	virtual void Unknown018() = 0;													        		//008C
	virtual void Unknown019() = 0;	 			                    								//0090
	virtual void Unknown020() = 0;																	//0094
	virtual void Unknown021() = 0;  																//0098
	virtual void Unknown022() = 0;								        							//009C
	virtual void Unknown023() = 0;																	//00A0
	virtual void Unknown024() = 0;																	//00A4
	virtual void Unknown025() = 0;																	//00A8
	virtual void Unknown026() = 0;																	//00AC
	virtual void Unknown027() = 0;											                		//00B0
	virtual void Unknown028() = 0;													        		//00B4
	virtual void Unknown029() = 0;	 			                    								//00B8
	virtual void Unknown030() = 0;																	//00BC
	virtual void Unknown031() = 0;  																//00C0
	virtual void Unknown032() = 0;								        							//00C4
	virtual void Unknown033() = 0;																	//00C8
	virtual void Unknown034() = 0;																	//00CC
	virtual void Unknown035() = 0;																	//00D0
	virtual void Unknown036() = 0;																	//00D4
	virtual void Unknown037() = 0;											                		//00D8
	virtual void Unknown038() = 0;													        		//00DC
	virtual void Unknown039() = 0;	 			                    								//00E0
	virtual void Unknown040() = 0;																	//00E4
	virtual void Unknown041() = 0;  																//00E8
	virtual void Unknown042() = 0;								        							//00EC
	virtual void Unknown043() = 0;																	//00F0
	virtual void Unknown044() = 0;																	//00F4
	virtual void Unknown045() = 0;																	//00F8
	virtual void Unknown046() = 0;																	//00FC
	virtual void Unknown047() = 0;											                		//0100
	virtual void Unknown048() = 0;													        		//0104
	virtual void Unknown049() = 0;	 			                    								//0108
	virtual void Unknown050() = 0;																	//010C
	virtual void Unknown051() = 0;  																//0110
	virtual void Unknown052() = 0;								        							//0114
	virtual void Unknown053() = 0;																	//0118
	virtual void Unknown054() = 0;																	//011C
	virtual void Unknown055() = 0;																	//0120
	virtual void Unknown056() = 0;																	//0124
	virtual void Unknown057() = 0;											                		//0128
	virtual void Unknown058() = 0;													        		//012C
	virtual void Unknown059() = 0;	 			                    								//0130
	virtual void Unknown060() = 0;																	//0134
	virtual void Unknown061() = 0;  																//0138
	virtual void Unknown062() = 0;								        							//013C
	virtual void Unknown063() = 0;																	//0140
	virtual void Unknown064() = 0;																	//0144
	virtual void Unknown065() = 0;																	//0148
	virtual void Unknown066() = 0;																	//014C
	virtual void Unknown067() = 0;											                		//0150
	virtual void Unknown068() = 0;													        		//0154
	virtual void Unknown069() = 0;	 			                    								//0158
	virtual void Unknown070() = 0;																	//015C
	virtual void Unknown071() = 0;  																//0160
	virtual void Unknown072() = 0;								        							//0164
	virtual void Unknown073() = 0;																	//0168
	virtual void Unknown074() = 0;																	//016C
	virtual void Unknown075() = 0;																	//0170
	virtual void Unknown076() = 0;																	//0174
	virtual void Unknown077() = 0;											                		//0178
	virtual void Unknown078() = 0;													        		//017C
	virtual void Unknown079() = 0;	 			                    								//0180
	virtual void Unknown080() = 0;																	//0184
	virtual void Unknown081() = 0;  																//0188
	virtual void Unknown082() = 0;								        							//018C
	virtual void Unknown083() = 0;																	//0190
	virtual void Unknown084() = 0;																	//0194
	virtual void Unknown085() = 0;																	//0198
	virtual void Unknown086() = 0;																	//019C
	virtual void PaintTraverse(VPANEL panel) = 0;													//01A0
	virtual void Unknown0060() = 0;																	//01A4
	virtual void Unknown0061() = 0;																	//01A8
	virtual void Unknown0062() = 0;																	//01AC
	virtual void Unknown0063() = 0;																	//01B0
	virtual void Unknown0064() = 0;																	//01B4
	virtual void Unknown0065() = 0;																	//01B8
	virtual void Unknown0066() = 0;																	//01BC
	virtual void Unknown0067() = 0;																	//01C0
	virtual void Unknown0068() = 0;																	//01C4
	virtual void GetProportionalBase(int &width, int &height) = 0;									//01C8
	virtual void CalculateMouseVisible() = 0;														//01CC
	virtual bool NeedKBInput() = 0;																	//01D0
	virtual bool HasCursorPosFunctions() = 0;														//01D4
	virtual void SurfaceGetCursorPos(int &x, int &y) = 0;											//01D8
	virtual void SurfaceSetCursorPos(int x, int y) = 0;												//01DC
	virtual void DrawTexturedLine(const Vertex_t &a, const Vertex_t &b) = 0;						//01E0
	virtual void DrawOutlinedCircle(int x, int y, int radius, int segments) = 0;					//01E4
	virtual void DrawTexturedPolyLine(const Vertex_t *p, int n) = 0;								//01E8
	virtual void DrawTexturedSubRect(int x0, int y0, int x1, int y1,
		float texs0, float text0, float texs1, float text1) = 0;									//01EC
	virtual void DrawTexturedPolygon(int n, Vertex_t *pVertices) = 0;								//01F0
	virtual const wchar_t* GetTitle(VPANEL panel) = 0;												//01F4
	virtual bool IsCursorLocked(void) = 0;															//01F8
	virtual void SetWorkspaceInsets(int left, int top, int right, int bottom) = 0;					//01FC
	virtual bool DrawGetUnicodeCharRenderInfo(wchar_t ch, CharRenderInfo& info) = 0;				//0200
	virtual void DrawRenderCharFromInfo(const CharRenderInfo& info) = 0;							//0204
	virtual void DrawSetAlphaMultiplier(float alpha /* [0..1] */) = 0;								//0208
	virtual float DrawGetAlphaMultiplier() = 0;														//020C
	virtual void SetAllowHTMLJavaScript(bool state) = 0;											//0210
	virtual void OnScreenSizeChanged(int nOldWidth, int nOldHeight) = 0;							//0214
	virtual void Unknown0087() = 0;																	//0218
	virtual void Unknown0088() = 0;																	//021C
	virtual void PaintTraverseEx(VPANEL panel, bool paintPopups) = 0;								//0220
};

class IBaseInterface
{
public:
	virtual	~IBaseInterface() {}
};

class IPanel : public IBaseInterface
{
public:
	virtual void Init(VPANEL vguiPanel, void *panel) = 0;

	// methods
	virtual void SetPos(VPANEL vguiPanel, int x, int y) = 0;
	virtual void GetPos(VPANEL vguiPanel, int &x, int &y) = 0;
	virtual void Unknown001() = 0;
	virtual void SetSize(VPANEL vguiPanel, int wide, int tall) = 0;
	virtual void GetSize(VPANEL vguiPanel, int &wide, int &tall) = 0;
	virtual void SetMinimumSize(VPANEL vguiPanel, int wide, int tall) = 0;
	virtual void GetMinimumSize(VPANEL vguiPanel, int &wide, int &tall) = 0;
	virtual void SetZPos(VPANEL vguiPanel, int z) = 0;
	virtual int  GetZPos(VPANEL vguiPanel) = 0;
	virtual void GetAbsPos(VPANEL vguiPanel, int &x, int &y) = 0;
	virtual void GetClipRect(VPANEL vguiPanel, int &x0, int &y0, int &x1, int &y1) = 0;
	virtual void SetInset(VPANEL vguiPanel, int left, int top, int right, int bottom) = 0;
	virtual void GetInset(VPANEL vguiPanel, int &left, int &top, int &right, int &bottom) = 0;
	virtual void SetVisible(VPANEL vguiPanel, bool state) = 0;
	virtual bool IsVisible(VPANEL vguiPanel) = 0;
	virtual void SetParent(VPANEL vguiPanel, VPANEL newParent) = 0;
	virtual int GetChildCount(VPANEL vguiPanel) = 0;
	virtual VPANEL GetChild(VPANEL vguiPanel, int index) = 0;
	virtual VPANEL GetParent(VPANEL vguiPanel) = 0;
	virtual void MoveToFront(VPANEL vguiPanel) = 0;
	virtual void MoveToBack(VPANEL vguiPanel) = 0;
	virtual bool HasParent(VPANEL vguiPanel, VPANEL potentialParent) = 0;
	virtual bool IsPopup(VPANEL vguiPanel) = 0;
	virtual void SetPopup(VPANEL vguiPanel, bool state) = 0;
	virtual bool IsFullyVisible(VPANEL vguiPanel) = 0;
	virtual HScheme GetScheme(VPANEL vguiPanel) = 0;
	virtual bool IsProportional(VPANEL vguiPanel) = 0;
	virtual bool IsAutoDeleteSet(VPANEL vguiPanel) = 0;
	virtual void DeletePanel(VPANEL vguiPanel) = 0;
	virtual void Unknown002() = 0;
	virtual void Unknown003() = 0;
	virtual void SetKeyBoardInputEnabled(VPANEL vguiPanel, bool state) = 0;
	virtual void SetMouseInputEnabled(VPANEL vguiPanel, bool state) = 0;
	virtual bool IsKeyBoardInputEnabled(VPANEL vguiPanel) = 0;
	virtual bool IsMouseInputEnabled(VPANEL vguiPanel) = 0;
	virtual void Solve(VPANEL vguiPanel) = 0;
	virtual const char *GetName(VPANEL vguiPanel) = 0;
	virtual const char *GetClassName(VPANEL vguiPanel) = 0;
	virtual void SendMessage(VPANEL vguiPanel, void *params, VPANEL ifromPanel) = 0;
	virtual void Think(VPANEL vguiPanel) = 0;
	virtual void PerformApplySchemeSettings(VPANEL vguiPanel) = 0;
	virtual void PaintTraverse(VPANEL vguiPanel, bool forceRepaint, bool allowForce = true) = 0;
	virtual void Repaint(VPANEL vguiPanel) = 0;
	virtual VPANEL IsWithinTraverse(VPANEL vguiPanel, int x, int y, bool traversePopups) = 0;
	virtual void OnChildAdded(VPANEL vguiPanel, VPANEL child) = 0;
	virtual void OnSizeChanged(VPANEL vguiPanel, int newWide, int newTall) = 0;
	virtual void InternalFocusChanged(VPANEL vguiPanel, bool lost) = 0;
	virtual bool RequestInfo(VPANEL vguiPanel, void *outputData) = 0;
	virtual void RequestFocus(VPANEL vguiPanel, int direction = 0) = 0;
	virtual bool RequestFocusPrev(VPANEL vguiPanel, VPANEL existingPanel) = 0;
	virtual bool RequestFocusNext(VPANEL vguiPanel, VPANEL existingPanel) = 0;
	virtual VPANEL GetCurrentKeyFocus(VPANEL vguiPanel) = 0;
	virtual int GetTabPosition(VPANEL vguiPanel) = 0;
	virtual void *Plat(VPANEL vguiPanel) = 0;
	virtual void SetPlat(VPANEL vguiPanel, void *Plat) = 0;
	virtual void *GetPanel(VPANEL vguiPanel, const char *destinationModule) = 0;
	virtual bool IsEnabled(VPANEL vguiPanel) = 0;
	virtual void SetEnabled(VPANEL vguiPanel, bool state) = 0;
};

class ISetup
{
public:
	virtual void Unknown01() = 0;
	virtual void Unknown02() = 0;
	virtual void Unknown03() = 0;
	virtual void Unknown04() = 0;
	virtual ISurface* CreateSurfaceInterface(char* Version) = 0;
};

class IInput : public IBaseInterface
{
public:
	virtual void SetMouseFocus(VPANEL newMouseFocus) = 0;
	virtual void SetMouseCapture(VPANEL panel) = 0;
	virtual void GetKeyCodeText(KeyCode code, char *buf, int buflen) = 0;
	virtual VPANEL GetFocus() = 0;
	virtual VPANEL GetMouseOver() = 0;		// returns the panel the mouse is currently over, ignoring mouse capture
	virtual void SetCursorPos(int x, int y) = 0;
	virtual void GetCursorPos(int &x, int &y) = 0;
	virtual bool WasMousePressed(MouseCode code) = 0;
	virtual bool WasMouseDoublePressed(MouseCode code) = 0;
	virtual bool IsMouseDown(MouseCode code) = 0;
	virtual void SetCursorOveride(HCursor cursor) = 0;
	virtual HCursor GetCursorOveride() = 0;
	virtual bool WasMouseReleased(MouseCode code) = 0;
	virtual bool WasKeyPressed(KeyCode code) = 0;
	virtual bool IsKeyDown(KeyCode code) = 0;
	virtual bool WasKeyTyped(KeyCode code) = 0;
	virtual bool WasKeyReleased(KeyCode code) = 0;
	virtual VPANEL GetAppModalSurface() = 0;
	virtual void SetAppModalSurface(VPANEL panel) = 0;
	virtual void ReleaseAppModalSurface() = 0;
	virtual void GetCursorPosition(int &x, int &y) = 0;
	virtual void SetIMEWindow(void *hwnd) = 0;
	virtual void *GetIMEWindow() = 0;
	virtual void OnChangeIME(bool forward) = 0;
	virtual int  GetCurrentIMEHandle() = 0;
	virtual int  GetEnglishIMEHandle() = 0;
	virtual void GetIMELanguageName(wchar_t *buf, int unicodeBufferSizeInBytes) = 0;
	virtual void GetIMELanguageShortCode(wchar_t *buf, int unicodeBufferSizeInBytes) = 0;

	struct LanguageItem
	{
		wchar_t		shortname[4];
		wchar_t		menuname[128];
		int			handleValue;
		bool		active;
	};

	struct ConversionModeItem
	{
		wchar_t		menuname[128];
		int			handleValue;
		bool		active;
	};

	struct SentenceModeItem
	{
		wchar_t		menuname[128];
		int			handleValue;
		bool		active;
	};

	virtual int	 GetIMELanguageList(LanguageItem *dest, int destcount) = 0;
	virtual int	 GetIMEConversionModes(ConversionModeItem *dest, int destcount) = 0;
	virtual int	 GetIMESentenceModes(SentenceModeItem *dest, int destcount) = 0;
	virtual void OnChangeIMEByHandle(int handleValue) = 0;
	virtual void OnChangeIMEConversionModeByHandle(int handleValue) = 0;
	virtual void OnChangeIMESentenceModeByHandle(int handleValue) = 0;
	virtual void OnInputLanguageChanged() = 0;
	virtual void OnIMEStartComposition() = 0;
	virtual void OnIMEComposition(int flags) = 0;
	virtual void OnIMEEndComposition() = 0;
	virtual void OnIMEShowCandidates() = 0;
	virtual void OnIMEChangeCandidates() = 0;
	virtual void OnIMECloseCandidates() = 0;
	virtual void OnIMERecomputeModes() = 0;
	virtual int  GetCandidateListCount() = 0;
	virtual void GetCandidate(int num, wchar_t *dest, int destSizeBytes) = 0;
	virtual int  GetCandidateListSelectedItem() = 0;
	virtual int  GetCandidateListPageSize() = 0;
	virtual int  GetCandidateListPageStart() = 0;
	virtual void SetCandidateWindowPos(int x, int y) = 0;
	virtual bool GetShouldInvertCompositionString() = 0;
	virtual bool CandidateListStartsAtOne() = 0;
	virtual void SetCandidateListPageStart(int start) = 0;
	virtual void SetMouseCaptureEx(VPANEL panel, MouseCode captureStartMouseCode) = 0;
	virtual void RegisterKeyCodeUnhandledListener(VPANEL panel) = 0;
	virtual void UnregisterKeyCodeUnhandledListener(VPANEL panel) = 0;
	virtual void OnKeyCodeUnhandled(int keyCode) = 0;
	virtual void	SetModalSubTree(VPANEL subTree, VPANEL unhandledMouseClickListener, bool restrictMessagesToSubTree = true) = 0;
	virtual void	ReleaseModalSubTree() = 0;
	virtual VPANEL	GetModalSubTree() = 0;
	virtual void	SetModalSubTreeReceiveMessages(bool state) = 0;
	virtual bool	ShouldModalSubTreeReceiveMessages() const = 0;
	virtual VPANEL 	GetMouseCapture() = 0;
};

class IInputInternal : public IInput
{
public:
	virtual void RunFrame() = 0;
	virtual void UpdateMouseFocus(int x, int y) = 0;
	virtual void PanelDeleted(VPANEL panel) = 0;
	virtual bool InternalCursorMoved(int x, int y) = 0; //expects input in surface space
	virtual bool InternalMousePressed(MouseCode code) = 0;
	virtual bool InternalMouseDoublePressed(MouseCode code) = 0;
	virtual bool InternalMouseReleased(MouseCode code) = 0;
	virtual bool InternalMouseWheeled(int delta) = 0;
	virtual bool InternalKeyCodePressed(KeyCode code) = 0;
	virtual void InternalKeyCodeTyped(KeyCode code) = 0;
	virtual void InternalKeyTyped(wchar_t unichar) = 0;
	virtual bool InternalKeyCodeReleased(KeyCode code) = 0;
	virtual HInputContext CreateInputContext() = 0;
	virtual void DestroyInputContext(HInputContext context) = 0;
	virtual void AssociatePanelWithInputContext(HInputContext context, VPANEL pRoot) = 0;
	virtual void ActivateInputContext(HInputContext context) = 0;
	virtual void PostCursorMessage() = 0;
	virtual void UpdateCursorPosInternal(int x, int y) = 0;
	virtual void HandleExplicitSetCursor() = 0;
	virtual void SetKeyCodeState(KeyCode code, bool bPressed) = 0;
	virtual void SetMouseCodeState(MouseCode code, MouseCodeState_t state) = 0;
	virtual void UpdateButtonState(const InputEvent_t &event) = 0;
};