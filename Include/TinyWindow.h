//created my Ziyad Barakat 2014 - 2015

#ifndef TINYWINDOW_H
#define TINYWINDOW_H

#if defined( _WIN32 ) || defined( _WIN64 )
#include <Windows.h>
#include <gl/GL.h>
#include <io.h>
#include <fcntl.h>

LRESULT CALLBACK WindowProc( HWND windowHandle, UINT message, WPARAM wordParam, LPARAM longParam );
//this automatically loads the OpenGL library if you are using Visual studio 
#pragma comment ( lib, "opengl32.lib" )
//this makes sure that the entry point of your program is main(). not Winmain()
#pragma comment( linker, "/subsystem:windows /ENTRY:mainCRTStartup" )
#endif

#if defined( __linux__ )
#include <GL/glx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <string.h>

const int DEFAULT_WINDOW_WIDTH = 1280;
const int DEFAULT_WINDOW_HEIGHT = 720;

const int KEYSTATE_DOWN = 1;										/**< the key is currently up */
const int KEYSTATE_UP = 0;											/**< the key is currently down */

const int KEY_ERROR = -1;											/**< the key pressed is considered invalid */

const int KEY_FIRST = 256 + 1;										/**< the fist key that is not a char */
const int KEY_F1 = KEY_FIRST;										/**< the F1 key */
const int KEY_F2 = KEY_FIRST + 1;									/**< the F2 key */
const int KEY_F3 = KEY_FIRST + 2;									/**< the F3 key */
const int KEY_F4 = KEY_FIRST + 3;									/**< the F4 key */
const int KEY_F5 = KEY_FIRST + 4;									/**< the F5 key */
const int KEY_F6 = KEY_FIRST + 5;									/**< the F6 key */
const int KEY_F7 = KEY_FIRST + 6;									/**< the F7 key */
const int KEY_F8 = KEY_FIRST + 7;									/**< the F8 key */
const int KEY_F9 = KEY_FIRST + 8;									/**< the F9 key */
const int KEY_F10 = KEY_FIRST + 9;									/**< the F10 key */
const int KEY_F11 = KEY_FIRST + 10;									/**< the F11 key */
const int KEY_F12 = KEY_FIRST + 11;									/**< the F12 key */
const int KEY_CAPSLOCK = KEY_FIRST + 12;							/**< the CapsLock key */
const int KEY_LEFTSHIFT = KEY_FIRST + 13;							/**< the left Shift key */
const int KEY_RIGHTSHIFT = KEY_FIRST + 14;							/**< the right Shift key */
const int KEY_LEFTCONTROL = KEY_FIRST + 15;							/**< the left Control key */
const int KEY_RIGHTCONTROL = KEY_FIRST + 16;						/**< the right Control key */
const int KEY_LEFTWINDOW = KEY_FIRST + 17;							/**< the left Window key */
const int KEY_RIGHTWINDOW = KEY_FIRST + 18;							/**< the right Window key */
const int KEY_LEFTALT = KEY_FIRST + 19;								/**< the left Alternate key */
const int KEY_RIGHTALT = KEY_FIRST + 20;							/**< the right Alternate key */
const int KEY_ENTER = KEY_FIRST + 21;								/**< the Enter/Return key */
const int KEY_PRINTSCREEN = KEY_FIRST + 22;							/**< the PrintScreen key */
const int KEY_SCROLLLOCK = KEY_FIRST + 23;							/**< the ScrollLock key */
const int KEY_NUMLOCK = KEY_FIRST + 24;								/**< the NumLock key */
const int KEY_PAUSE = KEY_FIRST + 25;								/**< the pause/break key */
const int KEY_INSERT = KEY_FIRST + 26;								/**< the insert key */
const int KEY_HOME = KEY_FIRST + 27;								/**< the Home key */
const int KEY_END = KEY_FIRST + 28;									/**< the End key */
const int KEY_PAGEUP = KEY_FIRST + 28;								/**< the PageUp key */
const int KEY_PAGEDOWN = KEY_FIRST + 30;							/**< the PageDown key */
const int KEY_ARROW_DOWN = KEY_FIRST + 31;							/**< the ArrowDown key */
const int KEY_ARROW_UP = KEY_FIRST + 32;							/**< the ArrowUp key */
const int KEY_ARROW_LEFT = KEY_FIRST + 33;							/**< the ArrowLeft key */
const int KEY_ARROW_RIGHT = KEY_FIRST + 34;							/**< the ArrowRight key */
const int KEY_KEYPAD_DIVIDE = KEY_FIRST + 35;						/**< the KeyPad Divide key */
const int KEY_KEYPAD_MULTIPLY = KEY_FIRST + 36;						/**< the Keypad Multiply key */
const int KEY_KEYPAD_SUBTRACT = KEY_FIRST + 37;						/**< the Keypad Subtract key */
const int KEY_KEYPAD_ADD = KEY_FIRST + 38;							/**< the Keypad Add key */
const int KEY_KEYPAD_ENTER = KEY_FIRST + 39;						/**< the Keypad Enter key */
const int KEY_KEYPAD_PERIOD = KEY_FIRST + 40;						/**< the Keypad Period/Decimal key */
const int KEY_KEYPAD_0 = KEY_FIRST + 41;							/**< the Keypad 0 key */
const int KEY_KEYPAD_1 = KEY_FIRST + 42;							/**< the Keypad 1 key */
const int KEY_KEYPAD_2 = KEY_FIRST + 43;							/**< the Keypad 2 key */
const int KEY_KEYPAD_3 = KEY_FIRST + 44;							/**< the Keypad 3 key */
const int KEY_KEYPAD_4 = KEY_FIRST + 45;							/**< the Keypad 4 key */
const int KEY_KEYPAD_5 = KEY_FIRST + 46;							/**< the Keypad 5 key */
const int KEY_KEYPAD_6 = KEY_FIRST + 47;							/**< the Keypad 6 key */
const int KEY_KEYPAD_7 = KEY_FIRST + 48;							/**< the Keypad 7 key */
const int KEY_KEYPAD_8 = KEY_FIRST + 49;							/**< the keypad 8 key */
const int KEY_KEYPAD_9 = KEY_FIRST + 50;							/**< the Keypad 9 key */
const int KEY_BACKSPACE = KEY_FIRST + 51;							/**< the Backspace key */
const int KEY_TAB = KEY_FIRST + 52;									/**< the Tab key */
const int KEY_DELETE = KEY_FIRST + 53;								/**< the Delete key */
const int KEY_ESCAPE = KEY_FIRST + 54;								/**< the Escape key */
const int KEY_LAST = KEY_ESCAPE;									/**< the last key to be supported */

const int LEFT_CONTROL_DOWN_LONG = 29;
const int RIGHT_CONTROL_DOWN_LONG = 285;
const int LEFT_SHIFT_DOWN_LONG = 42;
const int RIGHT_SHIFT_DOWN_LONG = 54;
const int LEFT_ALT_DOWN_LONG = 8248;
const int RIGHT_ALT_DOWN_LONG = 8504;

const int LEFT_CONTROL_UP_LONG = 49181;
const int RIGHT_CONTROL_UP_LONG = 49437;
const int LEFT_SHIFT_UP_LONG = 49194;
const int RIGHT_SHIFT_UP_LONG = 49206;
const int LEFT_ALT_UP_LONG = 49208;
const int RIGHT_ALT_UP_LONG = 49464;

const int MOUSE_BUTTONUP = 0;										/**< the mouse button is currently up */
const int MOUSE_BUTTONDOWN = 1;										/**< the mouse button is currently down */

const int MOUSE_LEFTBUTTON = 0;										/**< the left mouse button */
const int MOUSE_RIGHTBUTTON = 1;									/**< the right mouse button */
const int MOUSE_MIDDLEBUTTON = 2;									/**< the middle mouse button / ScrollWheel */
const int MOUSE_LAST = MOUSE_MIDDLEBUTTON + 1;						/**< the last mouse button to be supported */

const int MOUSE_SCROLL_DOWN = 0;									/**< the mouse wheel up */
const int MOUSE_SCROLL_UP = 1;										/**< the mouse wheel down */

const int WINDOWSTYLE_BARE = 1;										/**< the window has no decorators but the window border and title bar */
const int WINDOWSTYLE_DEFAULT = 2;									/**< the default window style for the respective platform */
const int WINDOWSTYLE_POPUP = 3;									/**< the window has no decorators */

const int WINDOWSTATE_NORMAL = 0;									/**< the window is in its default state */
const int WINDOWSTATE_MAXIMIZED = 1;								/**< the window is currently maximized */
const int WINDOWSTATE_MINIMIZED = 2;								/**< the window is currently minimized */
const int WINDOWSTATE_FULLSCREEN = 3;								/**< the window is currently full screen */

const int DECORATOR_TITLEBAR = 0x01;								/**< The title bar decoration of the window */
const int DECORATOR_ICON = 0x02;									/**< the icon decoration of the window */
const int DECORATOR_BORDER = 0x04;									/**< the border decoration of the window */
const int DECORATOR_MINIMIZEBUTTON = 0x08;							/**< the minimize button decoration of the window */
const int DECORATOR_MAXIMIZEBUTTON = 0x010;							/**< the maximize button decoration pf the window */
const int DECORATOR_CLOSEBUTTON = 0x20;								/**< the close button decoration of the window */
const int DECORATOR_SIZEABLEBORDER = 0x40;							/**< the sizable border decoration of the window */

const int LINUX_DECORATOR_BORDER = 1L << 1;
const int LINUX_DECORATOR_MOVE = 1L << 2;
const int LINUX_DECORATOR_MINIMIZE = 1L << 3;
const int LINUX_DECORATOR_MAXIMIZE = 1L << 4;
const int LINUX_DECORATOR_CLOSE = 1L << 5;

const bool TINYWINDOW_ERROR = 0;
const bool TINYWINDOW_OK = 1;

const int TINYWINDOW_ERROR_NO_CONTEXT = 0;							/**< if a window tries to use a graphical function without a context */
const int TINYWINDOW_ERROR_INVALID_WINDOW_NAME = 1;					/**< if an invalid window name was given */
const int TINYWINDOW_ERROR_INVALID_WINDOW_INDEX = 2;				/**< if an invalid window index was given */
const int TINYWINDOW_ERROR_INVALID_WINDOW_STATE = 3;				/**< if an invalid window state was given */
const int TINYWINDOW_ERROR_INVALID_RESOLUTION = 4;					/**< if an invalid window resolution was given */
const int TINYWINDOW_ERROR_INVALID_CONTEXT = 5;						/**< if the OpenGL context for the window is invalid */
const int TINYWINDOW_ERROR_EXISTING_CONTEXT = 6;					/**< if the window already has an OpenGL context */
const int TINYWINDOW_ERROR_NOT_INITIALIZED = 7;						/**< if the window is being used without being initialized */
const int TINYWINDOW_ERROR_ALREADY_INITIALIZED = 8;					/**< if the window was already initialized */
const int TINYWINDOW_ERROR_INVALID_TITLEBAR = 9;					/**< if the Title-bar text given was invalid */
const int TINYWINDOW_ERROR_INVALID_EVENT = 10;						/**< if the given event callback was invalid */
const int TINYWIDNOW_ERROR_WINDOW_NOT_FOUND = 11;					/**< if the window was not found in the window manager */
const int TINYWINDOW_ERROR_INVALID_WINDOWSTYLE = 12;				/**< if the window style gives is invalid */
const int TINYWINDOW_ERROR_INVALID_WINDOW = 13;
const int TINYWINDOW_ERROR_FUNCTION_NOT_IMPLEMENTED = 14;			/**< if the function has not yet been implemented in the current version of the API */
const int TINYWINDOW_ERROR_LINUX_CANNOT_CONNECT_X_SERVER = 15;		/**< Linux: if cannot connect to X11 server */
const int TINYWINDOW_ERROR_LINUX_INVALID_VISUALINFO = 16;			/**< Linux: if visual information given was invalid */
const int TINYWINDOW_ERROR_LINUX_CANNOT_CREATE_WINDOW = 17;			/**< Linux: when X11 fails to create a new window */
const int TINYWINDOW_ERROR_LINUX_FUNCTION_NOT_IMPLEMENTED = 18;		/**< Linux: when the function has not yet been implemented on the Linux in the current version of the API */
const int TINYWINDOW_ERROR_WINDOWS_CANNOT_CREATE_WINDOW = 19;		/**< Windows: when Win32 cannot create a window */
const int TINYWINDOW_ERROR_WINDOWS_CANNOT_INITIALIZE = 20;			/**< Windows: when Win32 cannot initialize */
const int TINYWINDOW_ERROR_WINDOWS_FUNCTION_NOT_IMPLEMENTED = 21;	/**< Windows: when a function has yet to be implemented on the Windows platform in the current version of the API */

const int TINYWINDOW_WARNING_NOT_CURRENT_CONTEXT = 0;				/**< if using calling member functions of a window that is not the current window being drawn to */
const int TINYWINDOW_WARNING_NO_GL_EXTENSIONS = 1;					/**< if your computer does not support any OpenGL extensions */

const int LINUX_FUNCTION = 1;
const int LINUX_DECORATOR = 2;

typedef void( *onKeyEvent_t )( unsigned int key, bool keyState );										/**< To be called when a key event has occurred */
typedef void( *onMouseButtonEvent_t )( unsigned int button, bool buttonState );							/**< To be called when a Mouse button event has occurred */
typedef void( *onMouseWheelEvent_t )( unsigned int wheelDirection );											/**< To be called when a mouse wheel event has occurred. */
typedef void( *onDestroyedEvent_t )( void );															/**< To be called when the window is being destroyed */
typedef void( *onMaximizedEvent_t )( void );															/**< To be called when the window has been maximized */
typedef void( *onMinimizedEvent_t )( void );															/**< To be called when the window has been minimized */

//typedef ( *OnRestoredEvent )(); //only really works on windows, Linux doesn't even have an atomic for it. might need to remove

typedef void( *onFocusEvent_t )( bool inFocus );													/**< To be called when the window has gained event focus */
typedef void( *onMovedEvent_t )( unsigned int x, unsigned int y );													/**< To be called when the window has been moved */
typedef void( *onResizeEvent_t )( unsigned int width, unsigned int height );										/**< To be called when the window has been resized */
typedef void( *onMouseMoveEvent_t )( unsigned int windowX, unsigned int windowY, unsigned int screenX, unsigned int screenY );	/**< To be called when the mouse has been moved within the window */

//print the warning message associated with the given warning number
/*
static void TinyWindow_PrintWarningMessage( GLuint warningNumber )
{
	switch ( warningNumber )
	{
		case TINYWINDOW_WARNING_NO_GL_EXTENSIONS:
		{
			printf( "Warning: no OpenGL extensions available \n" );
			break;
		}

		case TINYWINDOW_WARNING_NOT_CURRENT_CONTEXT:
		{
			printf( "Warning: window not the current OpenGL context being rendered to \n" );
			break;
		}

		default:
		{
			printf( "Warning: unspecified warning \n" );
			break;
		}
	}
}*/

//print out the error associated with the given error number
static void TinyWindow_PrintErrorMessage( const unsigned int errorNumber )
{
	switch ( errorNumber )
	{
		case TINYWINDOW_ERROR_NO_CONTEXT:
		{
			printf( "Error: An OpenGL context must first be created( initialize the window ) \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_WINDOW_NAME:
		{
			printf( "Error: invald window name \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_WINDOW_INDEX:
		{
			printf( "Error: invalid window index \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_WINDOW_STATE:
		{
			printf( "Error: invalid window state \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_RESOLUTION:
		{
			printf( "Error: invalid resolution \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_CONTEXT:
		{
			printf( "Error: Failed to create OpenGL context \n" );
			break;
		}

		case TINYWINDOW_ERROR_EXISTING_CONTEXT:
		{
			printf( "Error: context already created \n" );
			break;
		}

		case TINYWINDOW_ERROR_NOT_INITIALIZED:
		{
			printf( "Error: Window manager not initialized \n" );
			break;
		}

		case TINYWINDOW_ERROR_ALREADY_INITIALIZED:
		{
			printf( "Error: window has already been initialized \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_TITLEBAR:
		{
			printf( "Error: invalid title bar name ( cannot be null or nullptr ) \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_EVENT:
		{
			printf( "Error: invalid event callback given \n" );
			break;
		}

		case TINYWIDNOW_ERROR_WINDOW_NOT_FOUND:
		{
			printf( "Error: window was not found \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_WINDOWSTYLE:
		{
			printf( "Error: invalid window style given \n" );
			break;
		}

		case TINYWINDOW_ERROR_INVALID_WINDOW:
		{
			printf( "Error: invalid window given \n" );
			break;
		}

		case TINYWINDOW_ERROR_FUNCTION_NOT_IMPLEMENTED:
		{
			printf( "Error: I'm sorry but this function has not been implemented yet :( \n" );
			break;
		}

		case TINYWINDOW_ERROR_LINUX_CANNOT_CONNECT_X_SERVER:
		{
			printf( "Error: cannot connect to X server \n" );
			break;
		}

		case TINYWINDOW_ERROR_LINUX_INVALID_VISUALINFO:
		{
			printf( "Error: Invalid visual information given \n" );
			break;
		}

		case TINYWINDOW_ERROR_LINUX_CANNOT_CREATE_WINDOW:
		{
			printf( "Error: failed to create window \n" );
			break;
		}

		case TINYWINDOW_ERROR_LINUX_FUNCTION_NOT_IMPLEMENTED:
		{
			printf( "Error: function not implemented on linux platform yet. sorry :( \n" );
			break;
		}

		case TINYWINDOW_ERROR_WINDOWS_CANNOT_CREATE_WINDOW:
		{
			printf( "Error: failed to create window \n" );
			break;
		}

		case TINYWINDOW_ERROR_WINDOWS_FUNCTION_NOT_IMPLEMENTED:
		{
			printf( "Error: function not implemented on Windows platform yet. sorry ;( \n" );
			break;
		}

		default:
		{
			printf( "Error: unspecified Error \n" );
			break;
		}
	}
}

class windowManager
{
public:

	windowManager(){}

	/**
	 * shutdown and delete all windows in the manager
	 */
	~windowManager( void )
	{
		if ( !GetInstance()->windowList.empty() )
		{
			for ( auto CurrentWindow : GetInstance()->windowList )
			{
				delete CurrentWindow;
			}
			GetInstance()->windowList.clear();
		}
	}

	/**
	 * use this to shutdown the window manager when your program is finished
	 */
	 static inline void ShutDown( void ) 
	{
		for ( auto CurrentWindow : GetInstance()->windowList )
		{
			delete CurrentWindow;
		}

#if defined( CURRENT_OS_LINUX )
		XCloseDisplay( GetInstance()->currentDisplay );
#endif

		GetInstance()->windowList.clear();
		delete instance;
	}

	/**
	 *use this to add a window to the manager. returns a pointer to the manager which allows for the easy creation of multiple windows
	 */
	static inline windowManager* AddWindow( const char* windowName, unsigned int width = DEFAULT_WINDOW_WIDTH, unsigned int height = DEFAULT_WINDOW_HEIGHT, unsigned int colourBits = 8, unsigned int depthBits = 8, unsigned int stencilBits = 8 )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( IsValid( windowName ) )
			{
				window_t* newWindow = new window_t;
				newWindow->name = windowName;
				newWindow->resolution[ 0 ] = width;
				newWindow->resolution[ 1 ] = height;
				newWindow->colourBits = colourBits;
				newWindow->depthBits = depthBits;
				newWindow->stencilBits = stencilBits;

				GetInstance()->windowList.push_back( newWindow );
				newWindow->iD = GetNumWindows() - 1;

				InitializeWindow( newWindow );

				return GetInstance();
			}
			return nullptr;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}

	/**
	 * return the total amount of windows the manager has
	 */
	static inline unsigned int GetNumWindows( void )
	{
		if ( GetInstance()->IsInitialized() )
		{
			return GetInstance()->windowList.size();
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the mouse position in screen co-ordinates
	 */
	static inline bool GetMousePositionInScreen( unsigned int& x, unsigned int& y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			x = GetInstance()->screenMousePosition[ 0 ];
			y = GetInstance()->screenMousePosition[ 1 ];
			return (bool)TINYWINDOW_OK;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * return the mouse position in screen co-ordinates
	 */
	static inline unsigned int* GetMousePositionInScreen( void )
	{
		if ( GetInstance()->IsInitialized() )
		{
			return GetInstance()->screenMousePosition;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}

	/**
	 * set the position of the mouse cursor relative to screen co-ordinates
	 */
	static inline bool SetMousePositionInScreen( unsigned int x, unsigned int y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			GetInstance()->screenMousePosition[ 0 ] = x;
			GetInstance()->screenMousePosition[ 1 ] = y;

#if defined( _WIN32 ) || defined( _WIN64 )
			Windows_SetMousePositionInScreen();
#else
			Linux_SetMousePositionInScreen( x, y );
#endif
			return (bool)TINYWINDOW_OK;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the Resolution of the current screen
	 */
	static inline unsigned int* GetScreenResolution( void )
	{
		if ( GetInstance()->IsInitialized() )
		{
#if defined( _WIN32 ) || defined( _WIN64 )
			RECT screen;
			HWND desktop = GetDesktopWindow();
			GetWindowRect( desktop, &screen );

			GetInstance()->screenResolution[ 0 ] = screen.right;
			GetInstance()->screenResolution[ 1 ] = screen.bottom;
			return GetInstance()->screenResolution;

#else
			GetInstance()->screenResolution[ 0 ] = WidthOfScreen( XDefaultScreenOfDisplay( GetInstance()->currentDisplay ) );
			GetInstance()->screenResolution[ 1 ] = HeightOfScreen( XDefaultScreenOfDisplay( GetInstance()->currentDisplay ) );

			return GetInstance()->screenResolution;
#endif
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}
	/**
	 * return the Resolution of the current screen
	 */
	static inline bool GetScreenResolution( unsigned int& width, unsigned int& Height )
	{
		if ( GetInstance()->IsInitialized() )
		{
#if defined( _WIN32 ) || defined( _WIN64 )
			RECT screen;
			HWND desktop = GetDesktopWindow();
			GetWindowRect( desktop, &screen );
			width = screen.right;
			Height = screen.bottom;
#else
			width = WidthOfScreen( XDefaultScreenOfDisplay( GetInstance()->currentDisplay ) );
			Height = HeightOfScreen( XDefaultScreenOfDisplay( GetInstance()->currentDisplay ) );

			GetInstance()->screenResolution[ 0 ] = width;
			GetInstance()->screenResolution[ 1 ] = Height;
#endif
			return (bool)TINYWINDOW_OK;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the Resolution of the given window by setting width and height
	 */
	static inline bool GetWindowResolutionByName( const char* windowName, unsigned int& width, unsigned int& height )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				width = GetWindowByName( windowName )->resolution[ 0 ];
				height = GetWindowByName( windowName )->resolution[ 1 ];
				return (bool)TINYWINDOW_ERROR;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * return the Resolution of the given window by setting width and height
	 */
	static inline bool GetWindowResolutionByIndex( unsigned int windowIndex, unsigned int& width, unsigned int& height )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				width = GetWindowByIndex( windowIndex )->resolution[ 0 ];
				height = GetWindowByIndex( windowIndex )->resolution[ 1 ];

				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the Resolution of the given Window as an array of doubles
	 */
	static inline unsigned int* GetWindowResolutionByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return GetWindowByName( windowName )->resolution;
			}
			return nullptr;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}
	/**
	 * return the Resolution of the Given Window as an array of doubles
	 */
	static inline unsigned int* GetWindowResolutionByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return GetWindowByIndex( windowIndex )->resolution;
			}
			return nullptr;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}

	/**
	 * set the Size/Resolution of the given window
	 */
	static inline bool SetWindowResolutionByName( const char* windowName, unsigned int width, unsigned int height )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->resolution[ 0 ] = width;
				GetWindowByName( windowName )->resolution[ 1 ] = height;
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowResolution( GetWindowByName( windowName ) );
#else
				Linux_SetWindowResolution( GetWindowByName( windowName ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_INVALID_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * set the Size/Resolution of the given window
	 */
	static inline bool SetWindowResolutionByIndex( unsigned int windowIndex, unsigned int width, unsigned int height )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( WindowExists( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->resolution[ 0 ] = width;
				GetWindowByIndex( windowIndex )->resolution[ 1 ] = height;

#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowResolution( GetWindowByIndex( windowIndex ) );
#else
				Linux_SetWindowResolution( GetWindowByIndex( windowIndex ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the Position of the given window relative to screen co-ordinates by setting X and Y
	 */ 
	static inline bool GetWindowPositionByName( const char* windowName, unsigned int& x, unsigned int& y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				x = GetWindowByName( windowName )->position[ 0 ];
				y = GetWindowByName( windowName )->position[ 1 ];
				return (bool)TINYWINDOW_OK;
			}

			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * return the Position of the given window relative to screen co-ordinates by setting X and Y
	 */
	static inline bool GetWindowPositionByIndex( unsigned int windowIndex, unsigned int& x, unsigned int& y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				x = GetWindowByIndex( windowIndex )->position[ 0 ];
				y = GetWindowByIndex( windowIndex )->position[ 1 ];
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the Position of the given window relative to screen co-ordinates as an array
	 */
	static inline unsigned int* GetWindowPositionByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return GetWindowByName( windowName )->position;
			}

			return nullptr;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}
	/**
	 * return the Position of the given window relative to screen co-ordinates as an array
	 */
	static inline unsigned int* GetWindowPositionByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return GetWindowByIndex( windowIndex )->position;
			}
			return nullptr;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}

	/**
	 * set the Position of the given window relative to screen co-ordinates
	 */
	static inline bool SetWindowPositionByName( const char* windowName, unsigned int x, unsigned int y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->position[ 0 ] = x;
				GetWindowByName( windowName )->position[ 1 ] = y;
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowPosition( GetWindowByName( windowName ) );
#else
				Linux_SetWindowPosition( GetWindowByName( windowName ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * set the position of the given window relative to screen co-ordinates
	 */
	static inline bool SetWindowPositionByName( unsigned int windowIndex, unsigned int x, unsigned int y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->position[ 0 ] = x;
				GetWindowByIndex( windowIndex )->position[ 1 ] = y;
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowPosition( GetWindowByIndex( windowIndex ) );
#else
				Linux_SetWindowPosition( GetWindowByIndex( windowIndex ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the mouse Position relative to the given window's co-ordinates by setting X and Y
	 */
	static inline bool GetMousePositionInWindowByName( const char* windowName, unsigned int& x, unsigned int& y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				x = GetWindowByName( windowName )->mousePosition[ 0 ];
				y = GetWindowByName( windowName )->mousePosition[ 1 ];
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * return the mouse position relative to the given window's co-ordinates by setting X and Y
	 */
	static inline bool GetMousePositionInWindowByIndex( unsigned int windowIndex, unsigned int& x, unsigned int& y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				x = GetWindowByIndex( windowIndex )->mousePosition[ 0 ];
				y = GetWindowByIndex( windowIndex )->mousePosition[ 1 ];
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return the mouse Position relative to the given window's co-ordinates as an array
	 */
	static inline unsigned int* GetMousePositionInWindowByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return GetWindowByName( windowName )->mousePosition;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}
	/**
	 * return the mouse Position relative to the given window's co-ordinates as an array
	 */
	static inline unsigned int* GetMousePositionInWindowByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return GetWindowByIndex( windowIndex )->mousePosition;
			}
			return nullptr;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return nullptr;
	}

	/**
	 * set the mouse Position of the given window's co-ordinates
	 */
	static inline bool SetMousePositionInWindowByName( const char* windowName, unsigned int x, unsigned int y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->mousePosition[ 0 ] = x;
				GetWindowByName( windowName )->mousePosition[ 1 ] = y;
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetMousePosition( GetWindowByName( windowName ) );
#else
				Linux_SetMousePosition( GetWindowByName( windowName ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * set the mouse Position of the given window's co-ordinates
	 */
	static inline bool SetMousePositionInWindowByIndex( unsigned int windowIndex, unsigned int x, unsigned int y )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->mousePosition[ 0 ] = x;
				GetWindowByIndex( windowIndex )->mousePosition[ 1 ] = y;
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetMousePosition( GetWindowByIndex( windowIndex ) );
#else
				Linux_SetMousePosition( GetWindowByIndex( windowIndex ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * returns the current state of the given key relative to the given window
	 */
	static inline bool WindowGetKeyByName( const char* windowName, unsigned int key )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return GetWindowByName( windowName )->keys[ key ];
			}

			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * returns the current state of the given key relative to the given window
	 */
	static inline bool WindowGetKeyByIndex( unsigned int windowIndex, unsigned int key )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return GetWindowByIndex( windowIndex )->keys[ key ];
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return whether the given window should be closing
	 */
	static inline bool GetWindowShouldCloseByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return GetWindowByName( windowName )->shouldClose;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * return whether the given window should be closing
	 */
	static inline bool GetWindowShouldCloseByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return GetWindowByIndex( windowIndex )->shouldClose;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * swap the draw buffers of the given window
	 */
	static inline bool WindowSwapBuffersByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				SwapBuffers( GetWindowByName( windowName )->deviceContextHandle );
#else
				glXSwapBuffers( GetDisplay(), GetWindowByName( windowName )->windowHandle );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * swap the draw buffers of the given window
	 */
	static inline bool WindowSwapBuffersByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				SwapBuffers( GetWindowByIndex( windowIndex )->deviceContextHandle );
#else
				glXSwapBuffers( GetDisplay(), GetWindowByIndex( windowIndex )->windowHandle );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * make the given window be the current OpenGL Context to be drawn to
	 */
	static inline bool MakeWindowCurrentContextByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{

#if defined( _WIN32 ) || defined( _WIN64 )
				wglMakeCurrent( GetWindowByName( windowName )->deviceContextHandle,
					GetWindowByName( windowName )->glRenderingContextHandle );
#else
				glXMakeCurrent( windowManager::GetDisplay(), GetWindowByName( windowName )->windowHandle,
					GetWindowByName( windowName )->context );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * make the given window be the current OpenGL Context to be drawn to
	 */
	static inline bool MakeWindowCurrentContextByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				wglMakeCurrent( GetWindowByIndex( windowIndex )->deviceContextHandle,
					GetWindowByIndex( windowIndex )->glRenderingContextHandle );
#else
				glXMakeCurrent( GetDisplay(), GetWindowByIndex( windowIndex )->windowHandle,
					GetWindowByIndex( windowIndex )->context );
#endif
				return (bool)TINYWINDOW_OK;
			}

			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NO_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return whether the given window is in fullscreen mode
	 */
	static inline bool GetWindowIsFullScreenByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return ( GetWindowByName( windowName )->currentState == WINDOWSTATE_FULLSCREEN );
			}

			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NO_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * return whether the given window is in fullscreen mode
	 */
	static inline bool GetWindowIsFullScreenByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return ( GetWindowByIndex( windowIndex )->currentState == WINDOWSTATE_FULLSCREEN );
			}

			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NO_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}	

	/**
	 * toggle the given window's full screen mode
	 */
	static inline bool SetFullScreenByName( const char* windowName, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				if ( newState )
				{
					GetWindowByName( windowName )->currentState = WINDOWSTATE_FULLSCREEN;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_FullScreen( GetWindowByName( windowName ) );
#else
					Linux_Fullscreen( GetWindowByName( windowName ) );
#endif

					return (bool)TINYWINDOW_OK;
				}

				else
				{
					GetWindowByName( windowName )->currentState = WINDOWSTATE_NORMAL;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_FullScreen( GetWindowByName( windowName ) );
#else
					Linux_Fullscreen( GetWindowByName( windowName ) );
#endif
					return (bool)TINYWINDOW_OK;
				}
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/*
	 * toggle the given window's full screen mode
	 */
	static inline bool SetFullScreenByIndex( unsigned int windowIndex, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				if ( newState )
				{
					GetWindowByIndex( windowIndex )->currentState = WINDOWSTATE_FULLSCREEN;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_FullScreen( GetWindowByIndex( windowIndex ) );
#else
					Linux_Fullscreen( GetWindowByIndex( windowIndex ) );
#endif
					return (bool)TINYWINDOW_OK;
				}

				else
				{
					GetWindowByIndex( windowIndex )->currentState = WINDOWSTATE_NORMAL;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_FullScreen( GetWindowByIndex( windowIndex ) );
#else
					Linux_Fullscreen( GetWindowByIndex( windowIndex ) );
#endif
					return (bool)TINYWINDOW_OK;
				}
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * returns whether the given window is minimized
	 */
	static inline bool GetWindowIsMinimizedByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return ( GetWindowByName( windowName )->currentState == WINDOWSTATE_MINIMIZED );
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * returns whether the given window is minimized
	 */
	static inline bool GetWindowIsMinimizedByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return ( GetWindowByIndex( windowIndex )->currentState == WINDOWSTATE_MINIMIZED );
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * toggle the minimization state of the given window
	 */
	static inline bool MinimizeWindowByName( const char* windowName, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				if ( newState )
				{
					GetWindowByName( windowName )->currentState = WINDOWSTATE_MINIMIZED;

#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_Minimize( GetWindowByName( windowName ), newState );
#else
					Linux_Minimize( GetWindowByName( windowName ) );
#endif
					return (bool)TINYWINDOW_OK;
				}

				else
				{
					GetWindowByName( windowName )->currentState = WINDOWSTATE_NORMAL;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_Minimize( GetWindowByName( windowName ), newState );
#else
					Linux_Minimize( GetWindowByName( windowName ) );
#endif
					return (bool)TINYWINDOW_OK;
				}
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NO_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * toggle the minimization state of the window
	 */
	static inline bool MinimizeWindowByIndex( unsigned int windowIndex, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				if ( newState )
				{
					GetWindowByIndex( windowIndex )->currentState = WINDOWSTATE_MINIMIZED;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_Minimize( GetWindowByIndex( windowIndex ), newState );
#else
					Linux_Minimize( GetWindowByIndex( windowIndex ) );
#endif
					return (bool)TINYWINDOW_OK;
				}

				else
				{
					GetWindowByIndex( windowIndex )->currentState = WINDOWSTATE_NORMAL;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_Minimize( GetWindowByIndex( windowIndex ), newState );
#else
					Linux_Minimize( GetWindowByIndex( windowIndex ) );
#endif
					return (bool)TINYWINDOW_OK;
				}
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * return whether the current window is currently maximized
	 */
	static inline bool GetWindowIsMaximizedByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return ( GetWindowByName( windowName )->currentState == WINDOWSTATE_MAXIMIZED );
			}

			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * return whether the given window is currently maximized
	 */
	static inline bool GetWindowIsMaximizedByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return ( GetWindowByIndex( windowIndex )->currentState == WINDOWSTATE_MAXIMIZED );
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	
	/**
	 * toggle the maximization state of the current window
	 */
	static inline bool MaximizeWindowByName( const char* windowName, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				if ( newState )
				{
					GetWindowByName( windowName )->currentState = WINDOWSTATE_MAXIMIZED;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_Maximize( GetWindowByName( windowName ), newState );
#else
					Linux_Maximize( GetWindowByName( windowName ) );
#endif
					return (bool)TINYWINDOW_OK;
				}

				else
				{
					GetWindowByName( windowName )->currentState = WINDOWSTATE_NORMAL;
#if defined( _WIN32 ) || defined( _WIN64 )
					Windows_Maximize( GetWindowByName( windowName ), newState );
#else
					Linux_Maximize( GetWindowByName( windowName ) );
#endif
					return (bool)TINYWINDOW_OK;
				}
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	/**
	 * toggle the maximization state of the current window
	 */
	static inline bool MaximizeWindowByIndex( unsigned int windowIndex, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_Maximize( GetWindowByIndex( windowIndex ), newState );
#else
				Linux_Maximize( GetWindowByIndex( windowIndex ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	/**
	 * gets and sets for window name and index
	 */
	static inline const char* GetWindowNameByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return GetWindowByIndex( windowIndex )->name;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline unsigned int GetWindowIndexByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return GetWindowByName( windowName )->iD;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	//set the window title bar
	static inline bool SetWindowTitleBarByName( const char* windowName, const char* newTitle )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) && IsValid( newTitle ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				SetWindowText( GetWindowByName( windowName )->windowHandle, newTitle );
#else
				XStoreName( GetDisplay(), GetWindowByName( windowName )->windowHandle, newTitle );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}			
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowTitleBarByIndex( unsigned int windowIndex, const char* newName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) && IsValid( newName ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				SetWindowText( GetWindowByIndex( windowIndex )->windowHandle, newName );
#else
				XStoreName( GetDisplay(), GetWindowByIndex( windowIndex )->windowHandle, newName );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowIconByName( const char* windowName, const char* icon, unsigned int width, unsigned int height )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) && IsValid( icon ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowIcon( GetWindowByName( windowName ), icon, width, height );
#else
				Linux_SetWindowIcon( GetWindowByName( windowName ), icon, width, height );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowIconByIndex( unsigned int windowIndex, const char* icon, unsigned int width, unsigned int height )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) && IsValid( icon ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowIcon( GetWindowByIndex( windowIndex ), icon, width, height );
#else
				Linux_SetWindowIcon( GetWindowByIndex( windowIndex ), icon, width, height );
#endif
				return (bool)TINYWINDOW_OK;
			}

			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	//gets and sets window is in focus
	static inline bool GetWindowIsInFocusByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				return GetWindowByName( windowName )->inFocus;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool GetWindowIsInFocusByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				return GetWindowByIndex( windowIndex )->inFocus;
			}
			return (bool)TINYWINDOW_ERROR;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool FocusWindowByName( const char* windowName, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_Focus( GetWindowByName( windowName ), newState );
#else
				Linux_Focus( GetWindowByName( windowName ), newState );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool FocusWindowByIndex( unsigned int windowIndex, bool newState )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_Focus( GetWindowByIndex( windowIndex ), newState );
#else
				Linux_Focus( GetWindowByIndex( windowIndex ), newState );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NO_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}

	//gets and sets for restoring the window
	static inline bool RestoreWindowByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_Restore( GetWindowByName( windowName ) );
#else
				Linux_Restore( GetWindowByName( windowName ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool RestoreWindowByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( WindowExists( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_Restore( GetWindowByIndex( windowIndex ) );
#else
				Linux_Restore( GetWindowByIndex( windowIndex ) );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NO_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}

	//initialize the window manager
	static inline bool Initialize( void )
	{
		GetInstance()->isInitialized = GL_FALSE;
#if defined( _WIN32 ) || defined( _WIN64 )
		return Windows_Initialize();
#else
		return Linux_Initialize();
#endif
	}

	static inline bool IsInitialized( void )
	{
		return GetInstance()->isInitialized;
	}

	//ask the window to poll for window events
	static inline void PollForEvents( void )
	{
		if ( GetInstance()->IsInitialized() )
		{
#if defined( _WIN32 ) || defined( _WIN64 )
			GetInstance()->Windows_PollForEvents();
#else
			GetInstance()->Linux_PollForEvents();
#endif
		}

		else
		{ 
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		}		
	}
	static inline void WaitForEvents( void )
	{
		if ( GetInstance()->IsInitialized() )
		{
#if defined( _WIN32 ) || defined( _WIN64 )
			GetInstance()->Windows_WaitForEvents();
#else
			GetInstance()->Linux_WaitForEvents();
#endif
		}

		else
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		}
	}

	//remove a window from the manager
	static inline bool RemoveWindowByName( const char* windowName ) 
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				ShutdownWindow( GetWindowByName( windowName ) );
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool RemoveWindowByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				ShutdownWindow( GetWindowByIndex( windowIndex ) );
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowStyleByName( const char* windowName, unsigned int windowStyle )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowStyle( GetWindowByName( windowName ), windowStyle );
#else
				Linux_SetWindowStyle( GetWindowByName( windowName ), windowStyle );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowStyleByIndex( unsigned int windowIndex, unsigned int windowStyle )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_SetWindowStyle( GetWindowByIndex( windowIndex ), windowStyle );
#else
				Linux_SetWindowStyle( GetWindowByIndex( windowIndex ), windowStyle );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool EnableWindowDecoratorsByName( const char* windowname, GLbitfield decorators )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowname ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_EnableDecorators( GetWindowByName( windowname ), decorators );
#else
				Linux_EnableDecorators( GetWindowByName( windowname ), decorators );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool EnableWindowDecoratorsByIndex( unsigned int windowIndex, GLbitfield decorators )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_EnableDecorators( GetWindowByIndex( windowIndex ), decorators );
#else
				Linux_EnableDecorators( GetWindowByIndex( windowIndex ), decorators );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool DisableWindowDecoratorByName( const char* windowName, GLbitfield decorators )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_DisableDecorators( GetWindowByName( windowName ), decorators );
#else
				Linux_DisableDecorators( GetWindowByName( windowName ), decorators );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool DisableWindowDecoratorByIndex( unsigned int windowIndex, GLbitfield decorators )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
#if defined( _WIN32 ) || defined( _WIN64 )
				Windows_DisableDecorators( GetWindowByIndex( windowIndex ), decorators );
#else
				Linux_DisableDecorators( GetWindowByIndex( windowIndex ), decorators );
#endif
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	//set callbacks for the selected window
	static inline bool SetWindowOnKeyEventByName( const char* windowName, onKeyEvent_t onKey )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->keyEvent = onKey;
				return (bool)TINYWINDOW_OK;
			}

			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnKeyEventByIndex( unsigned int windowIndex, onKeyEvent_t onKey )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->keyEvent = onKey;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnMouseButtonEventByName( const char* windowName, onMouseButtonEvent_t onMouseButton )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->mouseButtonEvent = onMouseButton;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnMouseButtonEventByIndex( unsigned int windowIndex, onMouseButtonEvent_t onMouseButton )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->mouseButtonEvent = onMouseButton;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnMouseWheelEventByName( const char* windowName, onMouseWheelEvent_t onMouseWheel )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->mouseWheelEvent = onMouseWheel;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnMouseWheelEventByIndex( unsigned int windowIndex, onMouseWheelEvent_t onMouseWheel )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->mouseWheelEvent = onMouseWheel;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnDestroyedByName( const char* windowName, onDestroyedEvent_t onDestroyed )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->destroyedEvent = onDestroyed;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnDestroyedByIndex( unsigned int windowIndex, onDestroyedEvent_t onDestroyed )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->destroyedEvent = onDestroyed;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnMaximizedByName( const char* windowName, onMaximizedEvent_t onMaximized )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->maximizedEvent = onMaximized;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnMaximizedByIndex( unsigned int windowIndex, onMaximizedEvent_t onMaximized )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->maximizedEvent = onMaximized;
					return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnMinimizedByName( const char* windowName, onMinimizedEvent_t onMinimized )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->minimizedEvent = onMinimized;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnMinimizedByIndex( unsigned int windowIndex, onMinimizedEvent_t onMinimized )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->minimizedEvent = onMinimized;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnFocusByName( const char* windowName, onFocusEvent_t onFocus )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->focusEvent = onFocus;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnFocusByIndex( unsigned int windowIndex, onFocusEvent_t onFocus )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->focusEvent = onFocus;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnMovedByName( const char* windowName, onMovedEvent_t onMoved )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->movedEvent = onMoved;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnMovedByIndex( unsigned int windowIndex, onMovedEvent_t onMoved )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->movedEvent = onMoved;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnResizeByName( const char* windowName, onResizeEvent_t onResize )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->resizeEvent = onResize;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnResizeByIndex( unsigned int windowIndex, onResizeEvent_t onResize )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->resizeEvent = onResize;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline bool SetWindowOnMouseMoveByName( const char* windowName, onMouseMoveEvent_t onMouseMove )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByName( windowName ) )
			{
				GetWindowByName( windowName )->mouseMoveEvent = onMouseMove;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}
	static inline bool SetWindowOnMouseMoveByIndex( unsigned int windowIndex, onMouseMoveEvent_t onMouseMove )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( DoesExistByIndex( windowIndex ) )
			{
				GetWindowByIndex( windowIndex )->mouseMoveEvent = onMouseMove;
				return (bool)TINYWINDOW_OK;
			}
			return (bool)TINYWINDOW_ERROR;
		}
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_NOT_INITIALIZED );
		return (bool)TINYWINDOW_ERROR;
	}

private:

	struct window_t
	{
		window_t()
		{
			name = nullptr;
			iD = NULL;
			colourBits = NULL;
			depthBits = NULL;
			stencilBits = NULL;
			shouldClose = GL_FALSE;
			currentState = WINDOWSTATE_NORMAL;
				
			keyEvent = nullptr;
			mouseButtonEvent = nullptr;
			mouseWheelEvent = nullptr;
			destroyedEvent = nullptr;
			maximizedEvent = nullptr;
			minimizedEvent = nullptr;
			focusEvent = nullptr;
			movedEvent = nullptr;
			resizeEvent = nullptr;
			mouseMoveEvent = nullptr;

			initialized = GL_FALSE;
			contextCreated = GL_FALSE;
			currentWindowStyle = WINDOWSTYLE_DEFAULT;

#if defined( __linux )
			context = 0;
#endif 
		}

		const char*					name;							/**< Name of the window */
		unsigned int				iD;								/**< ID of the Window. ( where it belongs in the window manager ) */
		unsigned int				colourBits;						/**< color format of the window. ( defaults to 32 bit color ) */
		unsigned int				depthBits;						/**< Size of the Depth buffer. ( defaults to 8 bit depth ) */
		unsigned int				stencilBits;					/**< Size of the stencil buffer, ( defaults to 8 bit ) */
		bool						keys[ KEY_LAST ];				/**< Record of keys that are either pressed or released in the respective window */
		bool						mouseButton[ MOUSE_LAST ];		/**< Record of mouse buttons that are either presses or released */
		unsigned int				resolution[ 2 ];				/**< Resolution/Size of the window stored in an array */
		unsigned int				position[ 2 ];					/**< Position of the Window relative to the screen co-ordinates */
		unsigned int				mousePosition[ 2 ];				/**< Position of the Mouse cursor relative to the window co-ordinates */
		bool						shouldClose;					/**< Whether the Window should be closing */
		bool						inFocus;						/**< Whether the Window is currently in focus( if it is the current window be used ) */

		bool						initialized;					/**< whether the window has been successfully initialized */
		bool						contextCreated;					/**< whether the OpenGL context has been successfully created */
		bool						isCurrentContext;				/**< whether the window is the current window being drawn to */

		unsigned int				currentState;					/**< The current state of the window. these states include Normal, Minimized, Maximized and Full screen */
		unsigned int				currentWindowStyle;				/**< the current style of the window */

		onKeyEvent_t				keyEvent;						/**< this is the callback to be used when a key has been pressed */
		onMouseButtonEvent_t		mouseButtonEvent;				/**< this is the callback to be used when a mouse button has been pressed */
		onMouseWheelEvent_t			mouseWheelEvent;				/**< this is the callback to be used when the mouse wheel has been scrolled. */
		onDestroyedEvent_t			destroyedEvent;					/**< this is the callback to be used when the window has been closed in a non-programmatic fashion */
		onMaximizedEvent_t			maximizedEvent;					/**< this is the callback to be used when the window has been maximized in a non-programmatic fashion */
		onMinimizedEvent_t			minimizedEvent;					/**< this is the callback to be used when the window has been minimized in a non-programmatic fashion */
		onFocusEvent_t				focusEvent;						/**< this is the callback to be used when the window has been given focus in a non-programmatic fashion */
		onMovedEvent_t				movedEvent;						/**< this is the callback to be used the window has been moved in a non-programmatic fashion */
		onResizeEvent_t				resizeEvent;					/**< this is a callback to be used when the window has been resized in a non-programmatic fashion */
		onMouseMoveEvent_t			mouseMoveEvent;					/**< this is a callback to be used when the mouse has been moved */

#if defined( _WIN32 ) || defined( _WIN64 )
			
		HDC							deviceContextHandle;
		HGLRC						glRenderingContextHandle;
		HPALETTE					paletteHandle;
		PIXELFORMATDESCRIPTOR		pixelFormatDescriptor;
		WNDCLASS					windowClass;
		HWND						windowHandle;
		HINSTANCE					instanceHandle;

#else
		Window						windowHandle;					/**< the X11 handle to the window. I wish they didn't name the type 'Window' */
		GLXContext					context;						/**< the handle to the GLX rendering context */
		XVisualInfo*				visualInfo;						/**< the handle to the Visual Information. similar purpose to PixelformatDesriptor */
		int*						attributes;						/**< attributes of the window. RGB, depth, stencil, etc */
		XSetWindowAttributes		setAttributes;					/**< the attributes to be set for the window */
		GLbitfield					decorators;						/**< enabled window decorators */

		/*these atomics are needed to change window states via the extended window manager
		I might move them to window manager considering these are essentially constants
			*/
		Atom						AtomState;						/**< atom for the state of the window */							// _NET_WM_STATE
		Atom						AtomHidden;						/**< atom for the current hidden state of the window */				// _NET_WM_STATE_HIDDEN
		Atom						AtomFullScreen;					/**< atom for the full screen state of the window */				// _NET_WM_STATE_FULLSCREEN
		Atom						AtomMaxHorz;					/**< atom for the maximized horizontally state of the window */		// _NET_WM_STATE_MAXIMIZED_HORZ
		Atom						AtomMaxVert;					/**< atom for the maximized vertically state of the window */		// _NET_WM_STATE_MAXIMIZED_VERT
		Atom						AtomClose;						/**< atom for closing the window */									// _NET_WM_CLOSE_WINDOW
		Atom						AtomActive;						/**< atom for the active window */									// _NET_ACTIVE_WINDOW
		Atom						AtomDemandsAttention;			/**< atom for when the window demands attention */					// _NET_WM_STATE_DEMANDS_ATTENTION
		Atom						AtomFocused;					/**< atom for the focused state of the window */					// _NET_WM_STATE_FOCUSED
		Atom						AtomCardinal;					/**< atom for cardinal coordinates */								// _NET_WM_CARDINAL
		Atom						AtomIcon;						/**< atom for the icon of the window */								// _NET_WM_ICON
		Atom						AtomHints;						/**< atom for the window decorations */								// _NET_WM_HINTS

		Atom						AtomWindowType;					/**< atom for the type of window */
		Atom						AtomWindowTypeDesktop;			/**< atom for the desktop window type */							//_NET_WM_WINDOW_TYPE_SPLASH
		Atom						AtomWindowTypeSplash;			/**< atom for the splash screen window type */
		Atom						AtomWindowTypeNormal;			/**< atom for the normal splash screen window type */

		Atom						AtomAllowedActions;				/**< atom for allowed window actions */
		Atom						AtomActionResize;				/**< atom for allowing the window to be resized */
		Atom						AtomActionMinimize;				/**< atom for allowing the window to be minimized */
		Atom						AtomActionShade;				/**< atom for allowing the window to be shaded */
		Atom						AtomActionMaximizeHorz;			/**< atom for allowing the window to be maximized horizontally */
		Atom						AtomActionMaximizeVert;			/**< atom for allowing the window to be maximized vertically */
		Atom						AtomActionClose;				/**< atom for allowing the window to be closed */

		Atom						AtomDesktopGeometry;			/**< atom for Desktop Geometry */
#endif
	};

	std::vector< window_t* >	windowList;
	static windowManager*		instance;

	unsigned int				screenResolution[ 2 ];
	unsigned int				screenMousePosition[ 2 ];

	bool						isInitialized;

	static inline bool IsValid( const char* stringParameter )
	{
		return ( stringParameter != nullptr );
	}

	static inline bool IsValid( onKeyEvent_t onKeyPressed )
	{
		return ( onKeyPressed != nullptr );
	}

	static inline bool IsValid( onMouseWheelEvent_t onMouseWheelEvent )
	{
		return ( onMouseWheelEvent != nullptr );
	}

	static inline bool IsValid( onMaximizedEvent_t onMaximized )
	{
		return ( onMaximized != nullptr );
	}

	static inline bool IsValid( onFocusEvent_t onFocus )
	{
		return ( onFocus != nullptr );
	}

	static inline bool IsValid( onMovedEvent_t onMoved )
	{
		return ( onMoved != nullptr );
	}

	static inline bool IsValid( onMouseMoveEvent_t onMouseMove )
	{
		return ( onMouseMove != nullptr );
	}	

	static inline bool WindowExists( unsigned int windowIndex )
	{
		return ( windowIndex <= GetInstance()->windowList.size() - 1 );
	}

	//get a static reference to the window manager
	static inline windowManager* GetInstance( void )
	{
		if ( windowManager::instance == nullptr )
		{
			windowManager::instance = new windowManager();
			return windowManager::instance;
		}

		else
		{
			return windowManager::instance;
		}
	}

	static inline void InitializeWindow( window_t* window )
	{
#if defined( _WIN32 ) || defined( _WIN64 )
		Windows_InitializeWindow( window );
#else
		Linux_InitializeWindow( window );
#endif
	}

	static inline void InitializeGL( window_t* window )
	{
#if defined( _WIN32 ) || defined( _WIN64 )
		Windows_InitializeGL( window );
#else
		Linux_InitializeGL( window );
#endif
	}

	static inline void ShutdownWindow( window_t* window )
	{
#if defined( _WIN32 ) || defined( _WIN64 )
		Windows_ShutdownWindow( window );
#else
		Linux_ShutdownWindow( window );
#endif
	}

	static inline bool DoesExistByName( const char* windowName )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( IsValid( windowName ) )
			{
				for ( auto window : GetInstance()->windowList )
				{
					if( !strcmp( window->name, windowName ) )
					{
						return GL_TRUE;
					}
				}
			}
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_INVALID_WINDOW_NAME );
			return GL_FALSE;
		}

		return GL_FALSE;
	}

	static inline bool DoesExistByIndex( unsigned int windowIndex )
	{
		if ( GetInstance()->IsInitialized() )
		{
			if ( windowIndex <= ( GetInstance()->windowList.size() - 1 ) )
			{
				return (bool)TINYWINDOW_OK;
			}

			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_INVALID_WINDOW_INDEX );
			return (bool)TINYWINDOW_ERROR;
		}

		return (bool)TINYWINDOW_ERROR;
	}

	static inline window_t* GetWindowByName( const char* windowName )
	{
			for( auto window : GetInstance()->windowList )
			{
				if ( !strcmp( window->name, windowName ) )
				{
					return window;
				}
			}

			return nullptr;
	}

	//return a static pointer to a window that corresponds to the given window index
	static inline window_t* GetWindowByIndex( unsigned int windowIndex )
	{
		if ( windowIndex <= GetInstance()->windowList.size() - 1 )
		{
			return GetInstance()->windowList[windowIndex];// GetWindowInList(windowIndex);
		}
		return nullptr;
	}
	
#if defined( _WIN32 ) || defined( _WIN64 )

	MSG		message;
	HDC		deviceContextHandle;

	//the windwow procedure for all windows. This is used mainly to handle window events
	LRESULT CALLBACK WindowProcedure( HWND windowHandle, unsigned int message, WPARAM wordParam, LPARAM longParam )
	{
		window_t* window = GetWindowByHandle( windowHandle );
		switch ( message )
		{
		case WM_CREATE:
		{
			GetWindowByIndex( windowList.size() - 1 )->windowHandle = windowHandle;
			window = GetWindowByHandle( windowHandle );

			InitializeGL( window );
			break;
		}

		case WM_DESTROY:
		{
			window->shouldClose = GL_TRUE;

			if ( IsValid( window->destroyedEvent ) )
			{
				window->destroyedEvent();
			}

			ShutdownWindow( window );
			break;
		}
		case WM_MOVE:
		{
			window->position[ 0 ] = LOWORD( longParam );
			window->position[ 1 ] = HIWORD( longParam );

			if ( IsValid( window->movedEvent ) )
			{
				window->movedEvent( window->position[ 0 ], window->position[ 1 ] );
			}

			break;
		}

		case WM_MOVING:
		{
			window->position[ 0 ] = LOWORD( longParam );
			window->position[ 1 ] = HIWORD( longParam );

			if ( IsValid( window->movedEvent ) )
			{
				window->movedEvent( window->position[ 0 ], window->position[ 1 ] );
			}
			break;
		}

		case WM_SIZE:
		{
			window->resolution[ 0 ] = ( unsigned int )LOWORD( longParam );
			window->resolution[ 1 ] = ( unsigned int )HIWORD( longParam );

			switch ( wordParam )
			{
				case SIZE_MAXIMIZED:
				{
					if ( IsValid( window->maximizedEvent ) )
					{
						window->maximizedEvent();
					}

					break;
				}

				case SIZE_MINIMIZED:
				{
					if ( IsValid( window->minimizedEvent ) )
					{
						window->minimizedEvent();
					}
					break;
				}

				default:
				{
					if ( IsValid( window->resizeEvent ) )
					{
						window->resizeEvent( window->resolution[ 0 ],
							window->resolution[ 1 ] );
					}

					break;
				}
			}
			break;
		}

		case WM_SIZING:
		{
			window->resolution[ 0 ] = ( unsigned int )LOWORD( longParam );
			window->resolution[ 1 ] = ( unsigned int )HIWORD( longParam );

			if ( IsValid( window->resizeEvent ) )
			{
				window->resizeEvent( window->resolution[ 0 ],
					window->resolution[ 1 ] );
			}

			break;
		}

		case WM_KEYDOWN:
		{
			unsigned int translatedKey = 0;

			switch ( HIWORD( longParam ) )
			{
			case LEFT_CONTROL_DOWN_LONG:
			{
				window->keys[ KEY_LEFTCONTROL ] = KEYSTATE_DOWN;
				translatedKey = KEY_LEFTCONTROL;
				break;
			}

			case RIGHT_CONTROL_DOWN_LONG:
			{
				window->keys[ KEY_RIGHTCONTROL ] = KEYSTATE_DOWN;
				translatedKey = KEY_RIGHTCONTROL;
				break;
			}

			case LEFT_SHIFT_DOWN_LONG:
			{
				window->keys[ KEY_LEFTSHIFT ] = KEYSTATE_DOWN;
				translatedKey = KEY_LEFTSHIFT;
				break;
			}

			case RIGHT_SHIFT_DOWN_LONG:
			{
				window->keys[ KEY_RIGHTSHIFT ] = KEYSTATE_DOWN;
				translatedKey = KEY_RIGHTSHIFT;
				break;
			}

			default:
			{
				translatedKey = Windows_TranslateKey( wordParam );
				window->keys[ translatedKey ] = KEYSTATE_DOWN;
				break;
			}
			}

			if ( IsValid( window->keyEvent ) )
			{
				window->keyEvent( translatedKey, KEYSTATE_DOWN );
			}
			break;
		}

		case WM_KEYUP:
		{
			unsigned int translatedKey = 0;

			switch ( HIWORD( longParam ) )
			{
			case LEFT_CONTROL_UP_LONG:
			{
				window->keys[ KEY_LEFTCONTROL ] = KEYSTATE_UP;
				translatedKey = KEY_LEFTCONTROL;
				break;
			}

			case RIGHT_CONTROL_UP_LONG:
			{
				window->keys[ KEY_RIGHTCONTROL ] = KEYSTATE_UP;
				translatedKey = KEY_RIGHTCONTROL;
				break;
			}

			case LEFT_SHIFT_UP_LONG:
			{
				window->keys[ KEY_LEFTSHIFT ] = KEYSTATE_UP;
				translatedKey = KEY_LEFTSHIFT;
				break;
			}

			case RIGHT_SHIFT_UP_LONG:
			{
				window->keys[ KEY_RIGHTSHIFT ] = KEYSTATE_UP;
				translatedKey = KEY_RIGHTSHIFT;
				break;
			}

			default:
			{
				translatedKey = Windows_TranslateKey( wordParam );
				window->keys[ translatedKey ] = KEYSTATE_UP;
				break;
			}
			}

			if ( IsValid( window->keyEvent ) )
			{
				window->keyEvent( translatedKey, KEYSTATE_UP );
			}
			break;
		}

		case WM_SYSKEYDOWN:
		{
			unsigned int translatedKey = 0;
			switch ( HIWORD( longParam ) )
			{
			case LEFT_ALT_DOWN_LONG:
			{
				window->keys[ KEY_LEFTALT ] = KEYSTATE_DOWN;
				translatedKey = KEY_LEFTALT;
				break;
			}


			case RIGHT_ALT_DOWN_LONG:
			{
				window->keys[ KEY_RIGHTALT ] = KEYSTATE_DOWN;
				translatedKey = KEY_RIGHTALT;
			}

			default:
			{
				break;
			}
			}

			if ( IsValid( window->keyEvent ) )
			{
				window->keyEvent( translatedKey, KEYSTATE_DOWN );
			}

			break;
		}

		case WM_SYSKEYUP:
		{
			unsigned int translatedKey = 0;
			switch ( HIWORD( longParam ) )
			{
			case LEFT_ALT_UP_LONG:
			{
				window->keys[ KEY_LEFTALT ] = KEYSTATE_UP;
				translatedKey = KEY_LEFTALT;
				break;
			}


			case RIGHT_ALT_UP_LONG:
			{
				window->keys[ KEY_RIGHTALT ] = KEYSTATE_UP;
				translatedKey = KEY_RIGHTALT;
				break;
			}

			default:
			{
				break;
			}
			}

			if ( IsValid( window->keyEvent ) )
			{
				window->keyEvent( translatedKey, KEYSTATE_UP );
			}
			break;
		}

		case WM_MOUSEMOVE:
		{
			window->mousePosition[ 0 ] = ( unsigned int )LOWORD( longParam );
			window->mousePosition[ 1 ] = ( unsigned int )HIWORD( longParam );

			POINT point;
			point.x = window->mousePosition[ 0 ];
			point.y = window->mousePosition[ 1 ];

			ClientToScreen( windowHandle, &point );

			if ( IsValid( window->mouseMoveEvent ) )
			{
				window->mouseMoveEvent( window->mousePosition[ 0 ],
					window->mousePosition[ 1 ], point.x, point.y );
			}
			break;
		}

		case WM_LBUTTONDOWN:
		{
			window->mouseButton[ MOUSE_LEFTBUTTON ] = MOUSE_BUTTONDOWN;

			if ( IsValid( window->mouseButtonEvent ) )
			{
				window->mouseButtonEvent( MOUSE_LEFTBUTTON, MOUSE_BUTTONDOWN );
			}
			break;
		}

		case WM_LBUTTONUP:
		{
			window->mouseButton[ MOUSE_LEFTBUTTON ] = MOUSE_BUTTONUP;

			if ( IsValid( window->mouseButtonEvent ) )
			{
				window->mouseButtonEvent( MOUSE_LEFTBUTTON, MOUSE_BUTTONUP );
			}
			break;
		}

		case WM_RBUTTONDOWN:
		{
			window->mouseButton[ MOUSE_RIGHTBUTTON ] = MOUSE_BUTTONDOWN;

			if ( IsValid( window->mouseButtonEvent ) )
			{
				window->mouseButtonEvent( MOUSE_RIGHTBUTTON, MOUSE_BUTTONDOWN );
			}
			break;
		}

		case WM_RBUTTONUP:
		{
			window->mouseButton[ MOUSE_RIGHTBUTTON ] = MOUSE_BUTTONUP;

			if ( IsValid( window->mouseButtonEvent ) )
			{
				window->mouseButtonEvent( MOUSE_RIGHTBUTTON, MOUSE_BUTTONUP );
			}
			break;
		}

		case WM_MBUTTONDOWN:
		{
			window->mouseButton[ MOUSE_MIDDLEBUTTON ] = MOUSE_BUTTONDOWN;

			if ( IsValid( window->mouseButtonEvent ) )
			{
				window->mouseButtonEvent( MOUSE_MIDDLEBUTTON, MOUSE_BUTTONDOWN );
			}
			break;
		}

		case WM_MBUTTONUP:
		{
			window->mouseButton[ MOUSE_MIDDLEBUTTON ] = MOUSE_BUTTONUP;

			if ( IsValid( window->mouseButtonEvent ) )
			{
				window->mouseButtonEvent( MOUSE_MIDDLEBUTTON, MOUSE_BUTTONUP );
			}
			break;
		}

		case WM_MOUSEWHEEL:
		{
			if ( ( wordParam % WHEEL_DELTA ) > 0 )
			{
				if ( IsValid( window->mouseWheelEvent ) )
				{
					window->mouseWheelEvent( MOUSE_SCROLL_DOWN );
				}
			}

			else
			{
				if ( IsValid( window->mouseWheelEvent ) )
				{
					window->mouseWheelEvent( MOUSE_SCROLL_UP );
				}

			}
			break;
		}

		default:
		{
			return DefWindowProc( windowHandle, message, wordParam, longParam );
		}
		}
		return 0;

	}

	//this returns a static reference to the win32 window procedure. Oddly a Win32 procedure cannot be a member variable
	static LRESULT CALLBACK StaticWindowProcedure( HWND windowHandle, UINT message, WPARAM wordParam, LPARAM longParam )
	{
		return windowManager::GetInstance()->WindowProcedure( windowHandle, message, wordParam, longParam );
	}

	//get the window that is associated with this Win32 window handle
	static inline window_t* GetWindowByHandle( HWND windowHandle )
	{
		for ( unsigned int iter = 0; iter < GetInstance()->windowList.size(); iter++ )
		{
			if ( GetInstance()->windowList[iter]->windowHandle == windowHandle )
			{
				return GetInstance()->windowList[iter];
			}
		}

		return nullptr;
	}

	//set the window resolution of the given window using Win32
	static inline void Windows_SetWindowResolution( window_t* window )
	{
		SetWindowPos( window->windowHandle, HWND_TOP,
			window->position[ 0 ], window->position[ 1 ],
			window->resolution[ 0 ], window->resolution[ 1 ],
			SWP_SHOWWINDOW | SWP_NOMOVE );
	}

	//set the position of the current window relative to screen co-ordinates using Win32
	static inline void Windows_SetWindowPosition( window_t* window )
	{
		SetWindowPos( window->windowHandle, HWND_TOP,
			window->position[ 0 ], window->position[ 1 ],
			window->resolution[ 0 ], window->resolution[ 1 ],
			SWP_SHOWWINDOW | SWP_NOSIZE );
	}

	//initialize the given window using Win32
	static inline void Windows_InitializeWindow( window_t* window,
		UINT style = CS_OWNDC | CS_HREDRAW | CS_DROPSHADOW,
		int clearScreenExtra = 0,
		int windowExtra = 0,
		HINSTANCE instance = GetModuleHandle( 0 ),
		HICON icon = LoadIcon( 0, IDI_APPLICATION ),
		HCURSOR cursor = LoadCursor( 0, IDC_ARROW ),
		HBRUSH brush = ( HBRUSH )BLACK_BRUSH )
	{
		window->instanceHandle = instance;
		window->windowClass.style = style;
		window->windowClass.lpfnWndProc = windowManager::StaticWindowProcedure;
		window->windowClass.cbClsExtra = clearScreenExtra;
		window->windowClass.cbWndExtra = windowExtra;
		window->windowClass.hInstance = window->instanceHandle;
		window->windowClass.hIcon = icon;
		window->windowClass.hCursor = cursor;
		window->windowClass.hbrBackground = brush;
		window->windowClass.lpszMenuName = window->name;
		window->windowClass.lpszClassName = window->name;
		RegisterClass( &window->windowClass );

		window->windowHandle =
			CreateWindow( window->name, window->name, WS_OVERLAPPEDWINDOW, 0,
			0, window->resolution[ 0 ],
			window->resolution[ 1 ],
			0, 0, 0, 0 );

		ShowWindow( window->windowHandle, GL_TRUE );
		UpdateWindow( window->windowHandle );
	}

	//initalize the pixel format for the selected window
	static inline void InitializePixelFormat( window_t* window )
	{
		window->pixelFormatDescriptor = {
			sizeof( PIXELFORMATDESCRIPTOR ), /* size */
			1, /* version */
			PFD_SUPPORT_OPENGL |
			PFD_DRAW_TO_WINDOW |
			PFD_DOUBLEBUFFER, /* support double-buffering */
			PFD_TYPE_RGBA, /* color type */
			( BYTE )window->colourBits, 0, /* prefered color depth */
			0, 0,
			0, 0,
			0, 0,
			0, /* color bits ( ignored ) */ /* no alpha buffer */ /* alpha bits ( ignored ) */
			0, /* no accumulation buffer */
			0, 0, 0, 0, /* accum bits ( ignored ) */
			( BYTE )window->depthBits, /* depth buffer */
			( BYTE )window->stencilBits, /* no stencil buffer */
			0, /* no auxiliary buffers */
			PFD_MAIN_PLANE, /* main layer */
			0, /* reserved */
			0, 0, 0, /* no layer, visible, damage masks */
		};

		int LocalPixelFormat = ChoosePixelFormat( window->deviceContextHandle,
			&window->pixelFormatDescriptor );

		if ( LocalPixelFormat )
		{
			SetPixelFormat( window->deviceContextHandle, LocalPixelFormat,
				&window->pixelFormatDescriptor );
			return;
		}
		return;
	}

	static inline bool Windows_InitializeGL( window_t* window )
	{
		window->deviceContextHandle = GetDC( window->windowHandle );
		InitializePixelFormat( window );
		window->glRenderingContextHandle = wglCreateContext( window->deviceContextHandle );
		wglMakeCurrent( window->deviceContextHandle, window->glRenderingContextHandle );

		window->contextCreated = ( window->glRenderingContextHandle != nullptr );

		if ( window->contextCreated )
		{
			return (bool)TINYWINDOW_OK;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_INVALID_CONTEXT );
		return (bool)TINYWINDOW_ERROR;
	}

	static inline void Windows_ShutdownWindow( window_t* window )
	{
		if ( window->glRenderingContextHandle )
		{
			wglMakeCurrent( nullptr, nullptr );
			wglDeleteContext( window->glRenderingContextHandle );
		}

		if ( window->paletteHandle )
		{
			DeleteObject( window->paletteHandle );
		}
		ReleaseDC( window->windowHandle, window->deviceContextHandle );
		UnregisterClass( window->name, window->instanceHandle );

		FreeModule( window->instanceHandle );

		window->deviceContextHandle = nullptr;
		window->windowHandle = nullptr;
		window->glRenderingContextHandle = nullptr;
	}

	static inline void Windows_FullScreen( window_t* window )
	{
		SetWindowLongPtr( window->windowHandle, GWL_STYLE,
			WS_SYSMENU | WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE );

		MoveWindow( window->windowHandle, 0, 0, windowManager::GetScreenResolution()[ 0 ],
			windowManager::GetScreenResolution()[ 1 ], GL_TRUE );
	}

	static inline void Windows_Minimize( window_t* window, bool newState )
	{
		if ( newState )
		{
			ShowWindow( window->windowHandle, SW_MINIMIZE );
		}

		else
		{
			ShowWindow( window->windowHandle, SW_RESTORE );
		}
	}

	static inline void Windows_Maximize( window_t* window, bool newState )
	{
		if ( newState )
		{
			ShowWindow( window->windowHandle, SW_MAXIMIZE );
		}

		else
		{
			ShowWindow( window->windowHandle, SW_RESTORE );
		}
	}

	static inline void Windows_Restore( window_t* window )
	{
		ShowWindow( window->windowHandle, SW_RESTORE );
	}
	
	static inline void Windows_Focus( window_t* window, bool newState )
	{
		window->inFocus = newState;

		if ( newState )
		{
			SetFocus( window->windowHandle );
		}

		else
		{
			SetFocus( nullptr );
		}
	}

	static inline void Windows_SetMousePosition( window_t* window )
	{
		POINT mousePoint;
		mousePoint.x = window->mousePosition[ 0 ];
		mousePoint.y = window->mousePosition[ 1 ];
		ScreenToClient( window->windowHandle, &mousePoint );
		SetCursorPos( mousePoint.x, mousePoint.y );
	}

	static inline void Windows_SetPosition( window_t* window )
	{
		SetWindowPos( window->windowHandle, HWND_TOP,
			window->position[ 0 ], window->position[ 1 ],
			window->resolution[ 0 ], window->resolution[ 1 ],
			SWP_SHOWWINDOW | SWP_NOSIZE );
	}

	static inline void Windows_SetResolution( window_t* window )
	{
		SetWindowPos( window->windowHandle, HWND_TOP, 
			window->position[ 0 ], window->position[ 1 ],
			window->resolution[ 0 ], window->resolution[ 1 ], 
			SWP_SHOWWINDOW | SWP_NOMOVE );
	}

	static inline void Windows_PollForEvents( void )
	{
		//only process events if there are any to process
		if ( PeekMessage( &GetInstance()->message, 0, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage( &GetInstance()->message );
			DispatchMessage( &GetInstance()->message );
		}
	}
	static inline void Windows_WaitForEvents( void )
	{
		//process even if there aren't any to process
		GetMessage( &GetInstance()->message, 0, 0, 0 );
		TranslateMessage( &GetInstance()->message );
		DispatchMessage( &GetInstance()->message );
	}

	static inline bool Windows_Initialize( void )
	{
		CreateTerminal();
		RECT desktop;

		HWND desktopHandle = GetDesktopWindow();

		if ( desktopHandle )
		{

			GetWindowRect( desktopHandle, &desktop );

			GetInstance()->screenResolution[ 0 ] = desktop.right;
			GetInstance()->screenResolution[ 1 ] = desktop.bottom;
			GetInstance()->isInitialized = GL_TRUE;
			return (bool)TINYWINDOW_OK;
		}

		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_WINDOWS_CANNOT_INITIALIZE );
		return (bool)TINYWINDOW_ERROR;
	}
	
	static inline void Windows_Shutown( void )
	{

	}

	static inline void Windows_SetMousePositionInScreen( void )
	{
		SetCursorPos( GetInstance()->screenMousePosition[ 0 ],
			GetInstance()->screenMousePosition[ 1 ] );
	}

	static inline void CreateTerminal( void )
	{
		int conHandle;
		long stdHandle;
		FILE* fp;

		// allocate a console for this app
		AllocConsole();

		// redirect unbuffered STDOUT to the console
		stdHandle = ( long )GetStdHandle( STD_OUTPUT_HANDLE );
		conHandle = _open_osfhandle( stdHandle, _O_TEXT );
		fp = _fdopen( conHandle, "w" );
		*stdout = *fp;

		setvbuf( stdout, nullptr, _IONBF, 0 );
	}

	static inline unsigned int Windows_TranslateKey( WPARAM wordParam)
	{
		switch ( wordParam )
		{
			case VK_ESCAPE:
			{
				return KEY_ESCAPE;
			}

			case VK_F1:
			{
				return KEY_F1;
			}

			case VK_F2:
			{
				return KEY_F2;
			}

			case VK_F3:
			{
				return KEY_F3;
			}

			case VK_F4:
			{
				return KEY_F4;
			}

			case VK_F5:
			{
				return KEY_F5;
			}

			case VK_F6:
			{
				return KEY_F6;
			}

			case VK_F7:
			{
				return KEY_F7;
			}

			case VK_F8:
			{
				return KEY_F8;
			}

			case VK_F9:
			{
				return KEY_F9;
			}

			case VK_F10:
			{
				return KEY_F10;
			}

			case VK_F11:
			{
				return KEY_F11;
			}

			case VK_F12:
			{
				return KEY_F12;
			}

			case VK_BACK:
			{
				return KEY_BACKSPACE;
			}

			case VK_TAB:
			{
				return KEY_TAB;
			}

			case VK_CAPITAL:
			{
				return KEY_CAPSLOCK;
			}

			case VK_RETURN:
			{
				return KEY_ENTER;
			}

			case VK_PRINT:
			{
				return KEY_PRINTSCREEN;
			}

			case VK_SCROLL:
			{
				return KEY_SCROLLLOCK;
			}

			case VK_PAUSE:
			{
				return KEY_PAUSE;
			}

			case VK_INSERT:
			{
				return KEY_INSERT;
			}

			case VK_HOME:
			{
				return KEY_HOME;
			}

			case VK_DELETE:
			{
				return KEY_DELETE;
			}

			case VK_END:
			{
				return KEY_END;
			}

			case VK_PRIOR:
			{
				return KEY_PAGEUP;
			}

			case VK_NEXT:
			{
				return KEY_PAGEDOWN;
			}

			case VK_DOWN:
			{
				return KEY_ARROW_DOWN;
			}

			case VK_UP:
			{
				return KEY_ARROW_UP;
			}

			case VK_LEFT:
			{
				return KEY_ARROW_LEFT;
			}

			case VK_RIGHT:
			{
				return KEY_ARROW_RIGHT;
			}

			case VK_DIVIDE:
			{
				return KEY_KEYPAD_DIVIDE;
			}

			case VK_MULTIPLY:
			{
				return KEY_KEYPAD_MULTIPLY;
			}

			case VK_SUBTRACT:
			{
				return KEY_KEYPAD_DIVIDE;
			}

			case VK_ADD:
			{
				return KEY_KEYPAD_ADD;
			}

			case VK_DECIMAL:
			{
				return KEY_KEYPAD_PERIOD;
			}

			case VK_NUMPAD0:
			{
				return KEY_KEYPAD_0;
			}

			case VK_NUMPAD1:
			{
				return KEY_KEYPAD_1;
			}

			case VK_NUMPAD2:
			{
				return KEY_KEYPAD_2;
			}

			case VK_NUMPAD3:
			{
				return KEY_KEYPAD_3;
			}

			case VK_NUMPAD4:
			{
				return KEY_KEYPAD_4;
			}

			case VK_NUMPAD5:
			{
				return KEY_KEYPAD_5;
			}

			case VK_NUMPAD6:
			{
				return KEY_KEYPAD_6;
			}

			case VK_NUMPAD7:
			{
				return KEY_KEYPAD_7;
			}

			case VK_NUMPAD8:
			{
				return KEY_KEYPAD_8;
			}

			case VK_NUMPAD9:
			{
				return KEY_KEYPAD_9;
			}

			case VK_LWIN:
			{
				return KEY_LEFTWINDOW;
			}

			case VK_RWIN:
			{
				return KEY_RIGHTWINDOW;
			}

			default:
			{
				return wordParam;
			}
		}
	}

	static inline void Windows_SetWindowIcon( window_t* window, const char* icon, unsigned int width, unsigned int height )
	{
		SendMessage(window->windowHandle, (UINT)WM_SETICON, ICON_BIG, 
			(LPARAM)LoadImage(window->instanceHandle, icon, IMAGE_ICON, width, height, LR_LOADFROMFILE));
	}

	static inline void Windows_SetWindowStyle( window_t* window, unsigned int windowType )
	{
		switch ( windowType )
		{
		case WINDOWSTYLE_DEFAULT:
		{
			EnableWindowDecoratorsByName( window->name, DECORATOR_TITLEBAR | DECORATOR_BORDER |
				DECORATOR_CLOSEBUTTON | DECORATOR_MINIMIZEBUTTON | DECORATOR_MAXIMIZEBUTTON );
			break;
		}

		case WINDOWSTYLE_POPUP:
		{
			EnableWindowDecoratorsByName( window->name, 0 );
			break;
		}

		case WINDOWSTYLE_BARE:
		{
			EnableWindowDecoratorsByName( window->name, DECORATOR_TITLEBAR | DECORATOR_BORDER );
			break;
		}

		default:
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_INVALID_WINDOWSTYLE );
			break;
		}
		}
	}

	static inline void Windows_EnableDecorators( window_t* window, GLbitfield decorators )
	{
		window->currentWindowStyle = WS_VISIBLE | WS_CLIPSIBLINGS;

		if ( decorators & DECORATOR_BORDER )
		{
			window->currentWindowStyle |= WS_BORDER;
		}

		if ( decorators & DECORATOR_TITLEBAR )
		{
			window->currentWindowStyle |= WS_CAPTION;
		}

		if ( decorators & DECORATOR_ICON )
		{
			window->currentWindowStyle |= WS_ICONIC;
		}

		if ( decorators & DECORATOR_CLOSEBUTTON )
		{
			window->currentWindowStyle |= WS_SYSMENU;
		}

		if ( decorators & DECORATOR_MINIMIZEBUTTON )
		{
			window->currentWindowStyle |= WS_MINIMIZEBOX | WS_SYSMENU;
		}

		if ( decorators & DECORATOR_MAXIMIZEBUTTON )
		{
			window->currentWindowStyle |= WS_MAXIMIZEBOX | WS_SYSMENU;
		}

		if ( decorators & DECORATOR_SIZEABLEBORDER )
		{
			window->currentWindowStyle |= WS_SIZEBOX;
		}

		SetWindowLongPtr( window->windowHandle, GWL_STYLE,
			window->currentWindowStyle );
	}
	static inline void Windows_DisableDecorators( window_t* window, GLbitfield decorators )
	{
		if ( decorators & DECORATOR_BORDER )
		{
			window->currentWindowStyle &= ~WS_BORDER;
		}

		if ( decorators & DECORATOR_TITLEBAR )
		{
			window->currentWindowStyle &= ~WS_MAXIMIZEBOX;
		}

		if ( decorators & DECORATOR_ICON )
		{
			window->currentWindowStyle &= ~WS_ICONIC;
		}

		if ( decorators & DECORATOR_CLOSEBUTTON )
		{
			window->currentWindowStyle &= ~WS_SYSMENU;
		}

		if ( decorators & DECORATOR_MINIMIZEBUTTON )
		{
			window->currentWindowStyle &= ~WS_MINIMIZEBOX;
		}

		if ( decorators & DECORATOR_MAXIMIZEBUTTON )
		{
			window->currentWindowStyle &= ~WS_MAXIMIZEBOX;
		}

		if ( decorators & DECORATOR_SIZEABLEBORDER )
		{
			window->currentWindowStyle &= ~WS_SIZEBOX;
		}

		SetWindowLongPtr( window->windowHandle, GWL_STYLE,
			window->currentWindowStyle | WS_VISIBLE );
	}

#else

	const Display*		currentDisplay;
	XEvent				currentEvent;
	
	static window_t* GetWindowByHandle( Window windowHandle )
	{
		for( auto iter : GetInstance()->windowList )
		{
			if ( iter->windowHandle == windowHandle )
			{
				return iter;
			}
		}
		return nullptr;	
	}

	static window_t* GetWindowByEvent( XEvent currentEvent )
	{
		switch( currentEvent.type )
		{
			case Expose:
			{
				return GetWindowByHandle( currentEvent.xexpose.window );
			}	

			case DestroyNotify:
			{
				return GetWindowByHandle( currentEvent.xdestroywindow.window );
			}

			case CreateNotify:
			{
				return GetWindowByHandle( currentEvent.xcreatewindow.window );
			}	

			case KeyPress:
			{
				return GetWindowByHandle( currentEvent.xkey.window );
			}

			case KeyRelease:
			{
				return GetWindowByHandle( currentEvent.xkey.window );
			}

			case ButtonPress:
			{
				return GetWindowByHandle( currentEvent.xbutton.window );
			}

			case ButtonRelease:
			{
				return GetWindowByHandle( currentEvent.xbutton.window );
			}

			case MotionNotify:
			{
				return GetWindowByHandle( currentEvent.xmotion.window );
			}	

			case FocusIn:
			{
				return GetWindowByHandle( currentEvent.xfocus.window );
			}

			case FocusOut:
			{
				return GetWindowByHandle( currentEvent.xfocus.window );
			}

			case ResizeRequest:
			{
				return GetWindowByHandle( currentEvent.xresizerequest.window );
			}

			case ConfigureNotify:
			{
				return GetWindowByHandle( currentEvent.xconfigure.window );
			}

			case PropertyNotify:
			{
				return GetWindowByHandle( currentEvent.xproperty.window );
			}

			case GravityNotify:
			{
				return GetWindowByHandle( currentEvent.xgravity.window );
			}

			case ClientMessage:
			{
				return GetWindowByHandle( currentEvent.xclient.window );
			}

			case VisibilityNotify:
			{
				return GetWindowByHandle( currentEvent.xvisibility.window );
			}	

			default:
			{
				return nullptr;
			}
		}
	}

	static bool Linux_Initialize( void )
	{
		GetInstance()->currentDisplay = XOpenDisplay( 0 );

		if( !GetInstance()->currentDisplay )
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_LINUX_CANNOT_CONNECT_X_SERVER );
			return (bool)TINYWINDOW_ERROR;
		}

		GetInstance()->screenResolution[ 0 ] = WidthOfScreen( XScreenOfDisplay( GetInstance()->currentDisplay, 
			DefaultScreen( GetInstance()->currentDisplay ) ) );

		GetInstance()->screenResolution[ 1 ] = HeightOfScreen( XScreenOfDisplay( GetInstance()->currentDisplay,
			DefaultScreen( GetInstance()->currentDisplay ) ) );
		GetInstance()->isInitialized = GL_TRUE;
		return (bool)TINYWINDOW_OK;
	}

	static void InitializeAtomics( window_t* window )
	{
		unsigned int display = windowManager::GetDisplay();
		window->AtomState = XInternAtom( display, "_NET_WM_STATE", GL_FALSE );
		window->AtomFullScreen = XInternAtom( display, "_NET_WM_STATE_FULLSCREEN", GL_FALSE );
		window->AtomMaxHorz = XInternAtom( display, "_NET_WM_STATE_MAXIMIZED_HORZ", GL_FALSE );
		window->AtomMaxVert = XInternAtom( display, "_NET_WM_STATE_MAXIMIZED_VERT", GL_FALSE );
		window->AtomClose = XInternAtom( display, "WM_DELETE_WINDOW", GL_FALSE );
		window->AtomHidden = XInternAtom( display, "_NET_WM_STATE_HIDDEN", GL_FALSE );
		window->AtomActive = XInternAtom( display, "_NET_ACTIVE_WINDOW", GL_FALSE );
		window->AtomDemandsAttention = XInternAtom( display, "_NET_WM_STATE_DEMANDS_ATTENTION", GL_FALSE );	
		window->AtomFocused = XInternAtom( display, "_NET_WM_STATE_FOCUSED", GL_FALSE );
		window->AtomCardinal = XInternAtom( display, "CARDINAL", GL_FALSE );
		window->AtomIcon = XInternAtom( display, "_NET_WM_ICON", GL_FALSE );
		window->AtomHints = XInternAtom( display, "_MOTIF_WM_HINTS", GL_TRUE );

		window->AtomWindowType = XInternAtom( display, "_NET_WM_WINDOW_TYPE", GL_FALSE );
		window->AtomWindowTypeDesktop = XInternAtom( display, "_NET_WM_WINDOW_TYPE_UTILITY", GL_FALSE );
		window->AtomWindowTypeSplash = XInternAtom( display, "_NET_WM_WINDOW_TYPE_SPLASH", GL_FALSE );
		window->AtomWindowTypeNormal = XInternAtom( display, "_NET_WM_WINDOW_TYPE_NORMAL", GL_FALSE );

		window->AtomAllowedActions = XInternAtom( display, "_NET_WM_ALLOWED_ACTIONS", GL_FALSE );
		window->AtomActionResize = XInternAtom( display, "WM_ACTION_RESIZE", GL_FALSE );
		window->AtomActionMinimize = XInternAtom( display, "_WM_ACTION_MINIMIZE", GL_FALSE );
		window->AtomActionShade = XInternAtom( display, "WM_ACTION_SHADE", GL_FALSE );
		window->AtomActionMaximizeHorz = XInternAtom( display, "_WM_ACTION_MAXIMIZE_HORZ", GL_FALSE );
		window->AtomActionMaximizeVert = XInternAtom( display, "_WM_ACTION_MAXIMIZE_VERT", GL_FALSE );
		window->AtomActionClose = XInternAtom( display, "_WM_ACTION_CLOSE", GL_FALSE );

		window->AtomDesktopGeometry = XInternAtom( display, "_NET_DESKTOP_GEOMETRY", GL_FALSE );
	}

	static void Linux_InitializeWindow( window_t* window )
	{
		window->attributes = new int[ 5 ]{
			GLX_RGBA,
			GLX_DOUBLEBUFFER, 
			GLX_DEPTH_SIZE, 
			window->depthBits, 
			None};

		window->decorators = 1;
		window->currentWindowStyle |= LINUX_DECORATOR_CLOSE | LINUX_DECORATOR_MAXIMIZE | LINUX_DECORATOR_MINIMIZE | LINUX_DECORATOR_MOVE;

		if ( !windowManager::GetDisplay() )
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_LINUX_CANNOT_CONNECT_X_SERVER );
			exit( 0 );
		}

		//window->VisualInfo = glXGetVisualFromFBConfig( GetDisplay(), GetBestFrameBufferConfig( window ) ); 

		window->visualInfo = glXChooseVisual( windowManager::GetDisplay(), 0, window->attributes );

		if ( !window->visualInfo )
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_LINUX_INVALID_VISUALINFO );
			exit( 0 );
		}

		window->setAttributes.colormap = XCreateColormap( GetDisplay(),
			DefaultRootWindow( GetDisplay() ),
			window->visualInfo->visual, AllocNone );

		window->setAttributes.event_mask = ExposureMask | KeyPressMask 
			| KeyReleaseMask | MotionNotify | ButtonPressMask | ButtonReleaseMask
			| FocusIn | FocusOut | Button1MotionMask | Button2MotionMask | Button3MotionMask | 
			Button4MotionMask | Button5MotionMask | PointerMotionMask | FocusChangeMask
			| VisibilityChangeMask | PropertyChangeMask | SubstructureNotifyMask;
		
		window->windowHandle = XCreateWindow( windowManager::GetDisplay(),
			XDefaultRootWindow( windowManager::GetDisplay() ), 0, 0,
			window->resolution[ 0 ], window->resolution[ 1 ],
			0, window->visualInfo->depth, InputOutput,
			window->visualInfo->visual, CWColormap | CWEventMask,
			&window->setAttributes );

		if( !window->windowHandle )
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_LINUX_CANNOT_CREATE_WINDOW );
			exit( 0 );
		}

		XMapWindow( GetDisplay(), window->windowHandle );
		XStoreName( GetDisplay(), window->windowHandle,
			window->name );

		InitializeAtomics( window );

		XSetWMProtocols( GetDisplay(), window->windowHandle, &window->AtomClose, GL_TRUE );	

		Linux_InitializeGL( window );
		return GL_TRUE;
	}

	static bool Linux_InitializeGL( window_t* window )
	{
		if( !window->context )
		{
			window->context = glXCreateContext( 
					windowManager::GetDisplay(),
				window->visualInfo, 
				0,
			 	GL_TRUE );

			if( window->context )
			{
				glXMakeCurrent( GetDisplay(),
					window->windowHandle, 
					window->context );

				XWindowAttributes l_Attributes;

				XGetWindowAttributes( GetDisplay(),
					window->windowHandle, &l_Attributes );
				window->position[ 0 ] = l_Attributes.x;
				window->position[ 1 ] = l_Attributes.y;

				window->contextCreated = GL_TRUE;
				return (bool)TINYWINDOW_OK;
			}
		}

		else
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_EXISTING_CONTEXT );
			return (bool)TINYWINDOW_ERROR;	
		}

		return (bool)TINYWINDOW_ERROR;
	}

	static void Linux_ShutdownWindow( window_t* window )
	{
		if( window->currentState == WINDOWSTATE_FULLSCREEN )
		{
			RestoreWindowByName( window->name );
		}

		glXDestroyContext( windowManager::GetDisplay(), window->context );
		XUnmapWindow( windowManager::GetDisplay(), window->windowHandle );
		XDestroyWindow( windowManager::GetDisplay(), window->windowHandle );
		window->windowHandle = 0;
		window->context = 0;
	}

	static void Linux_Shutdown( void )
	{
		XCloseDisplay( GetInstance()->currentDisplay );
	}

	static void Linux_Fullscreen( window_t* window )
	{
		XEvent currentEvent;
		memset( &currentEvent, 0, sizeof( currentEvent ) );

		currentEvent.xany.type = ClientMessage;
		currentEvent.xclient.message_type = window->AtomState;
		currentEvent.xclient.format = 32;
		currentEvent.xclient.window = window->windowHandle;
		currentEvent.xclient.data.l[ 0 ] = window->currentState == WINDOWSTATE_FULLSCREEN;
		currentEvent.xclient.data.l[ 1 ] = window->AtomFullScreen;

		XSendEvent( windowManager::GetDisplay(),
			XDefaultRootWindow( windowManager::GetDisplay() ),
			0, SubstructureNotifyMask, &currentEvent );
	}

	static void Linux_Minimize( window_t* window )
	{
		if( window->currentState == WINDOWSTATE_MINIMIZED )
		{
			XIconifyWindow( windowManager::GetDisplay(),
				window->windowHandle, 0 );
		}

		else
		{
			XMapWindow( windowManager::GetDisplay(), window->windowHandle );
		}
	}

	static void Linux_Maximize( window_t* window )
	{
		XEvent currentEvent;
		memset( &currentEvent, 0, sizeof( currentEvent ) );

		currentEvent.xany.type = ClientMessage;
		currentEvent.xclient.message_type = window->AtomState;
		currentEvent.xclient.format = 32;
		currentEvent.xclient.window = window->windowHandle;
		currentEvent.xclient.data.l[ 0 ] = ( window->currentState == WINDOWSTATE_MAXIMIZED );
		currentEvent.xclient.data.l[ 1 ] = window->AtomMaxVert;
		currentEvent.xclient.data.l[ 2 ] = window->AtomMaxHorz;

		XSendEvent( windowManager::GetDisplay(),
			XDefaultRootWindow( windowManager::GetDisplay() ),
			0, SubstructureNotifyMask, &currentEvent );
	}

	static void Linux_Restore( window_t* window )
	{
		XMapWindow( windowManager::GetDisplay(), window->windowHandle );
	}

	static void Linux_Focus( window_t* window, bool newFocusState )
	{
		if( newFocusState )
		{
			XMapWindow( windowManager::GetDisplay(), window->windowHandle );
		}

		else
		{
			XUnmapWindow( windowManager::GetDisplay(), window->windowHandle );
		}
	}

	static void Linux_SetMousePosition( window_t* window )
	{
		XWarpPointer( 
			windowManager::GetInstance()->currentDisplay,
			window->windowHandle, window->windowHandle,
			window->position[ 0 ], window->position[ 1 ],
			window->resolution[ 0 ], window->resolution[ 1 ],
			window->mousePosition[ 0 ], window->mousePosition[ 1 ] );
	}

	static void Linux_SetWindowPosition( window_t* window )
	{
		XWindowChanges windowChanges;

		windowChanges.x = window->position[ 0 ];
		windowChanges.y = window->position[ 1 ];

		XConfigureWindow( 
			windowManager::GetDisplay(),
			window->windowHandle, CWX | CWY, &windowChanges );
	}

	static void Linux_SetWindowResolution( window_t* window )
	{
		XResizeWindow( windowManager::GetDisplay(),
			window->windowHandle, window->resolution[ 0 ], window->resolution[ 1 ] );	
	}

	static void Linux_ProcessEvents( XEvent currentEvent )
	{
		window_t* window = GetWindowByEvent( currentEvent );

		switch ( currentEvent.type )	
		{
			case Expose:
			{
				break;
			}

			case DestroyNotify:
			{
				//	printf( "blarg" );

				if ( IsValid( window->destroyedEvent ) )
				{
					window->destroyedEvent();

				}

				printf( "Window was destroyed\n" );
				ShutdownWindow( window );

				break;

			}

			/*case CreateNotify:
			{
			printf( "Window was created\n" );
			l_Window->InitializeGL();

			if( IsValid( l_Window->m_OnCreated ) )
			{
			l_Window->m_OnCreated();
			}

			break;
			} */

			case KeyPress:
			{
				unsigned int functionKeysym = XKeycodeToKeysym( 
					GetInstance()->currentDisplay, currentEvent.xkey.keycode, 1 );

				if ( functionKeysym <= 255 )
				{
					window->keys[ functionKeysym ] = KEYSTATE_DOWN;
					if ( IsValid( window->keyEvent ) )
					{
						window->keyEvent( functionKeysym, KEYSTATE_DOWN );
					}
				}

				else
				{
					window->keys[ Linux_TranslateKey( functionKeysym ) ] = KEYSTATE_DOWN;

					if ( IsValid( window->keyEvent ) )
					{
						window->keyEvent( Linux_TranslateKey( functionKeysym ), KEYSTATE_DOWN );
					}
				}

				break;
			}

			case KeyRelease:
			{
				bool isRetriggered = GL_FALSE;
				if ( XEventsQueued( GetInstance()->currentDisplay, QueuedAfterReading ) )
				{
					XEvent nextEvent;
					XPeekEvent( GetInstance()->currentDisplay, &nextEvent );

					if ( nextEvent.type == KeyPress &&
						nextEvent.xkey.time == currentEvent.xkey.time &&
						nextEvent.xkey.keycode == currentEvent.xkey.keycode )
					{
						unsigned int functionKeysym = XKeycodeToKeysym( GetInstance()->currentDisplay,
						nextEvent.xkey.keycode, 1 );

						XNextEvent( GetInstance()->currentDisplay, &currentEvent );
						window->keyEvent( Linux_TranslateKey( functionKeysym ), KEYSTATE_DOWN );
						isRetriggered = GL_TRUE;
					}
				}

				if ( !isRetriggered )
				{
					unsigned int functionKeysym = XKeycodeToKeysym( GetInstance()->currentDisplay,
						currentEvent.xkey.keycode, 1 );

					if ( functionKeysym <= 255 )
					{
						window->keys[ functionKeysym ] = KEYSTATE_UP;

						if ( IsValid( window->keyEvent ) )
						{
							window->keyEvent( functionKeysym, KEYSTATE_UP );
						}
					}

					else
					{
						window->keys[ Linux_TranslateKey( functionKeysym ) ] = KEYSTATE_UP;

						if ( IsValid( window->keyEvent ) )
						{
							window->keyEvent( Linux_TranslateKey( functionKeysym ), KEYSTATE_UP );
						}
					}

					if ( IsValid( window->keyEvent ) )
					{
						window->keyEvent( Linux_TranslateKey( functionKeysym ), KEYSTATE_UP );
					}
				}

				break;
			}

			case ButtonPress:
			{
				switch ( currentEvent.xbutton.button )
				{
				case 1:
				{
					window->mouseButton[ MOUSE_LEFTBUTTON ] = MOUSE_BUTTONDOWN;

					if ( IsValid( window->mouseButtonEvent ) )
					{
						window->mouseButtonEvent( MOUSE_LEFTBUTTON, MOUSE_BUTTONDOWN );
					}
					break;
				}

				case 2:
				{
					window->mouseButton[ MOUSE_MIDDLEBUTTON ] = MOUSE_BUTTONDOWN;

					if ( IsValid( window->mouseButtonEvent ) )
					{
						window->mouseButtonEvent( MOUSE_MIDDLEBUTTON, MOUSE_BUTTONDOWN );
					}
					break;
				}

				case 3:
				{
					window->mouseButton[ MOUSE_RIGHTBUTTON ] = MOUSE_BUTTONDOWN;

					if ( IsValid( window->mouseButtonEvent ) )
					{
						window->mouseButtonEvent( MOUSE_RIGHTBUTTON, MOUSE_BUTTONDOWN );
					}
					break;
				}

				case 4:
				{
					window->mouseButton[ MOUSE_SCROLL_UP ] = MOUSE_BUTTONDOWN;

					if ( IsValid( window->mouseWheelEvent ) )
					{
						window->mouseWheelEvent( MOUSE_SCROLL_DOWN );
					}
					break;
				}

				case 5:
				{
					window->mouseButton[ MOUSE_SCROLL_DOWN ] = MOUSE_BUTTONDOWN;

					if ( IsValid( window->mouseWheelEvent ) )
					{
						window->mouseWheelEvent( MOUSE_SCROLL_DOWN );
					}
					break;
				}

				default:
				{
					//need to add more mmouse buttons 
					break;
				}
				}

				break;
			}

			case ButtonRelease:
			{
				switch ( currentEvent.xbutton.button )
				{
				case 1:
				{
					//the left mouse button was released
					window->mouseButton[ MOUSE_LEFTBUTTON ] = MOUSE_BUTTONUP;

					if ( IsValid( window->mouseButtonEvent ) )
					{
						window->mouseButtonEvent( MOUSE_LEFTBUTTON, MOUSE_BUTTONUP );
					}
					break;
				}

				case 2:
				{
					//the middle mouse button was released
					window->mouseButton[ MOUSE_MIDDLEBUTTON ] = MOUSE_BUTTONUP;

					if ( IsValid( window->mouseButtonEvent ) )
					{
						window->mouseButtonEvent( MOUSE_MIDDLEBUTTON, MOUSE_BUTTONUP );
					}
					break;
				}

				case 3:
				{
					//the right mouse button was released
					window->mouseButton[ MOUSE_RIGHTBUTTON ] = MOUSE_BUTTONUP;

					if ( IsValid( window->mouseButtonEvent ) )
					{
						window->mouseButtonEvent( MOUSE_RIGHTBUTTON, MOUSE_BUTTONUP );
					}
					break;
				}

				case 4:
				{
					//the mouse wheel was scrolled up
					window->mouseButton[ MOUSE_SCROLL_UP ] = MOUSE_BUTTONDOWN;
					break;
				}

				case 5:
				{
					//the mouse wheel wasscrolled down
					window->mouseButton[ MOUSE_SCROLL_DOWN ] = MOUSE_BUTTONDOWN;
					break;
				}

				default:
				{
					//need to add more mouse buttons
					break;
				}
				}
				break;
			}

			//when the mouse/pointer device is moved
			case MotionNotify:
			{
				//set the windows mouse position to match the event
				window->mousePosition[ 0 ] =
					currentEvent.xmotion.x;

				window->mousePosition[ 1 ] =
					currentEvent.xmotion.y;

				///set the screen mouse position to match the event
				GetInstance()->screenMousePosition[ 0 ] = currentEvent.xmotion.x_root;
				GetInstance()->screenMousePosition[ 1 ] = currentEvent.xmotion.y_root;

				if ( IsValid( window->mouseMoveEvent ) )
				{
					window->mouseMoveEvent( currentEvent.xmotion.x,
						currentEvent.xmotion.y, currentEvent.xmotion.x_root,
						currentEvent.xmotion.y_root );
				}
				break;
			}

			//when the window goes out of focus
			case FocusOut:
			{
				window->inFocus = GL_FALSE;
				if ( IsValid( window->focusEvent ) )
				{
					window->focusEvent( 
						window->inFocus );
				}
				break;
			}

			//when the window is back in focus ( use to call restore callback? )
			case FocusIn:
			{
				window->inFocus = GL_TRUE;

				if ( IsValid( window->focusEvent ) )
				{
					window->focusEvent( window->inFocus );
				}
				break;
			}

			//when a request to resize the window is made either by 
			//dragging out the window or programmatically
			case ResizeRequest:
			{
				window->resolution[ 0 ] = currentEvent.xresizerequest.width;
				window->resolution[ 1 ] = currentEvent.xresizerequest.height;

				glViewport( 0, 0,
					window->resolution[ 0 ],
					window->resolution[ 1 ] );

				if ( IsValid( window->resizeEvent ) )
				{
					window->resizeEvent( currentEvent.xresizerequest.width,
						currentEvent.xresizerequest.height );
				}

				break;
			}

			//when a request to configure the window is made
			case ConfigureNotify:
			{
				glViewport( 0, 0, currentEvent.xconfigure.width,
					currentEvent.xconfigure.height );

				//check if window was resized
				if ( ( unsigned int )currentEvent.xconfigure.width != window->resolution[ 0 ]
					|| ( unsigned int )currentEvent.xconfigure.height != window->resolution[ 1 ] )
				{
					if ( IsValid( window->resizeEvent ) )
					{
						window->resizeEvent( currentEvent.xconfigure.width, currentEvent.xconfigure.height );
					}

					window->resolution[ 0 ] = currentEvent.xconfigure.width;
					window->resolution[ 1 ] = currentEvent.xconfigure.height;
				}

				//check if window was moved
				if ( ( unsigned int )currentEvent.xconfigure.x != window->position[ 0 ]
					|| ( unsigned int )currentEvent.xconfigure.y != window->position[ 1 ] )
				{
					if ( IsValid( window->movedEvent ) )
					{
						window->movedEvent( currentEvent.xconfigure.x, currentEvent.xconfigure.y );
					}

					window->position[ 0 ] = currentEvent.xconfigure.x;
					window->position[ 1 ] = currentEvent.xconfigure.y;
				}
				break;
			}

			case PropertyNotify:
			{
				//this is needed in order to read from the windows WM_STATE Atomic
				//to determine if the property notify event was caused by a client
				//iconify event( minimizing the window ), a maximise event, a focus 
				//event and an attention demand event. NOTE these should only be 
				//for eventts that are not triggered programatically 

				Atom type;
				int format;
				ulong numItems, bytesAfter;
				unsigned char*  properties = nullptr;

				XGetWindowProperty( windowManager::GetDisplay(), currentEvent.xproperty.window,
					window->AtomState,
					0, LONG_MAX, GL_FALSE, AnyPropertyType,
					&type, &format, &numItems, &bytesAfter,
					& properties );

				if (  properties && ( format == 32 ) )
				{
					//go through each property and match it to an existing Atomic state
					for ( unsigned int currentItem = 0; currentItem < numItems; currentItem++ )
					{
						long currentProperty = ( ( long* )(  properties ) )[ currentItem ];

						if ( currentProperty == window->AtomHidden )
						{
							//window was minimized
							if ( IsValid( window->minimizedEvent ) )
							{
								//if the minimized callback for the window was set							
								window->minimizedEvent();
							}
						}

						if ( currentProperty == window->AtomMaxVert ||
							currentProperty == window->AtomMaxVert )
						{
							//window was maximized
							if ( IsValid( window->maximizedEvent ) )
							{
								//if the maximized callback for the window was set
								window->maximizedEvent();
							}
						}

						if ( currentProperty == window->AtomFocused )
						{
							//window is now in focus. we can ignore this is as FocusIn/FocusOut does this anyway
						}

						if ( currentProperty == window->AtomDemandsAttention )
						{
							//the window demands attention like a celebrity
							printf( "window demands attention \n" );
						}
					}
				}

				break;
			}

			case GravityNotify:
			{
				//this is only supposed to pop up when the parent of this window( if any ) has something happen
				//to it so that this window can react to said event as well.
				break;
			}

			//check for events that were created by the TinyWindow manager
			case ClientMessage:
			{
				const char* atomName = XGetAtomName( windowManager::GetDisplay(), currentEvent.xclient.message_type );
				if ( IsValid( atomName ) )
				{
					//printf( "%s\n", l_AtomName );
				}

				if ( ( Atom )currentEvent.xclient.data.l[ 0 ] == window->AtomClose )
				{
					printf( "window closed\n" );
					window->shouldClose = GL_TRUE;
					if( IsValid( window->destroyedEvent ) )
					{
						window->destroyedEvent();
					}
					ShutdownWindow( window );

					break;
	
				}

				//check if fullscreen
				if ( ( Atom )currentEvent.xclient.data.l[ 1 ] == window->AtomFullScreen )
				{
					break;
				}
				break;
	
			}

			default:
			{
				return;
			}
		}
	}

	static void Linux_PollForEvents( void )
	{
		//if there are any events to process
		if( XEventsQueued( GetInstance()->GetDisplay(), QueuedAfterReading ) )
		{
			XNextEvent( GetInstance()->currentDisplay, &GetInstance()->currentEvent );

			XEvent currentEvent = GetInstance()->currentEvent;

			Linux_ProcessEvents( currentEvent );
		}
	}
	static void Linux_WaitForEvents( void )
	{
		//even if there aren't any events to process
		XNextEvent( GetInstance()->currentDisplay, &GetInstance()->currentEvent );

		XEvent currentEvent = GetInstance()->currentEvent;

		Linux_ProcessEvents( currentEvent );
	}

	//the linux methos of setting the mouse position on the screen
	static void Linux_SetMousePositionInScreen( unsigned int x, unsigned int y )
	{
		XWarpPointer( GetInstance()->currentDisplay, None,
			XDefaultRootWindow( GetInstance()->currentDisplay ), 0, 0, 
			GetScreenResolution()[ 0 ], 
			GetScreenResolution()[ 1 ], 
			x, y );
	}

	//get pointer to X11 display
	static Display* GetDisplay( void )
	{
		return GetInstance()->currentDisplay;
	}
	//debugging. used to determine what type of event was generated
	static const char* Linux_GetEventType( XEvent currentEvent )
	{
		switch ( currentEvent.type )
		{
		case MotionNotify:
		{
			return "Motion Notify Event\n";
		}

		case ButtonPress:
		{
			return "Button Press Event\n";
		}

		case ButtonRelease:
		{
			return "Button Release Event\n";
		}

		case ColormapNotify:
		{
			return "Color Map Notify event \n";
		}

		case EnterNotify:
		{
			return "Enter Notify Event\n";
		}

		case LeaveNotify:
		{
			return "Leave Notify Event\n";
		}

		case Expose:
		{
			return "Expose Event\n";
		}

		case GraphicsExpose:
		{
			return "Graphics expose event\n";
		}

		case NoExpose:
		{
			return "No Expose Event\n";
		}

		case FocusIn:
		{
			return "Focus In Event\n";
		}

		case FocusOut:
		{
			return "Focus Out Event\n";
		}

		case KeymapNotify:
		{
			return "Key Map Notify Event\n";
		}

		case KeyPress:
		{
			return "Key Press Event\n";
		}

		case KeyRelease:
		{
			return "Key Release Event\n";
		}

		case PropertyNotify:
		{
			return "Property Notify Event\n";
		}

		case ResizeRequest:
		{
			return "Resize Property Event\n";
		}

		case CirculateNotify:
		{
			return "Circulate Notify Event\n";
		}

		case ConfigureNotify:
		{
			return "configure Notify Event\n";
		}

		case DestroyNotify:
		{
			return "Destroy Notify Request\n";
		}

		case GravityNotify:
		{
			return "Gravity Notify Event \n";
		}

		case MapNotify:
		{
			return "Map Notify Event\n";
		}

		case ReparentNotify:
		{
			return "Reparent Notify Event\n";
		}

		case UnmapNotify:
		{
			return "Unmap notify event\n";
		}

		case MapRequest:
		{
			return "Map request event\n";
		}

		case ClientMessage:
		{
			return "Client Message Event\n";
		}

		case MappingNotify:
		{
			return "Mapping notify event\n";
		}

		case SelectionClear:
		{
			return "Selection Clear event\n";
		}

		case SelectionNotify:
		{
			return "Selection Notify Event\n";
		}

		case SelectionRequest:
		{
			return "Selection Request event\n";
		}

		case VisibilityNotify:
		{
			return "Visibility Notify Event\n";
		}

		default:
		{
			return 0;
		}
		}
	}

	//translate keys from X keys to TinyWindow Keys
	static unsigned int Linux_TranslateKey( unsigned int keySymbol )
	{
		switch ( keySymbol )
		{
		case XK_Escape:
		{
			return KEY_ESCAPE;
		}

		case XK_Home:
		{
			return KEY_HOME;
		}

		case XK_Left:
		{
			return KEY_ARROW_LEFT;
		}

		case XK_Right:
		{
			return KEY_ARROW_RIGHT;
		}

		case XK_Up:
		{
			return KEY_ARROW_UP;
		}

		case XK_Down:
		{
			return KEY_ARROW_DOWN;
		}

		case XK_Page_Up:
		{
			return KEY_PAGEUP;
		}

		case XK_Page_Down:
		{
			return KEY_PAGEDOWN;
		}

		case XK_End:
		{
			return KEY_END;
		}

		case XK_Print:
		{
			return KEY_PRINTSCREEN;
		}

		case XK_Insert:
		{
			return KEY_INSERT;
		}

		case XK_Num_Lock:
		{
			return KEY_NUMLOCK;
		}

		case XK_KP_Multiply:
		{
			return KEY_KEYPAD_MULTIPLY;
		}

		case XK_KP_Add:
		{
			return KEY_KEYPAD_ADD;
		}

		case XK_KP_Subtract:
		{
			return KEY_KEYPAD_SUBTRACT;
		}

		case XK_KP_Decimal:
		{
			return KEY_KEYPAD_PERIOD;
		}

		case XK_KP_Divide:
		{
			return KEY_KEYPAD_DIVIDE;
		}

		case XK_KP_0:
		{
			return KEY_KEYPAD_0;
		}

		case XK_KP_1:
		{
			return KEY_KEYPAD_1;
		}

		case XK_KP_2:
		{
			return KEY_KEYPAD_2;
		}

		case XK_KP_3:
		{
			return KEY_KEYPAD_3;
		}

		case XK_KP_4:
		{
			return KEY_KEYPAD_4;
		}

		case XK_KP_5:
		{
			return KEY_KEYPAD_5;
		}

		case XK_KP_6:
		{
			return KEY_KEYPAD_6;
		}

		case XK_KP_7:
		{
			return KEY_KEYPAD_7;
		}

		case XK_KP_8:
		{
			return KEY_KEYPAD_8;
		}

		case XK_KP_9:
		{
			return KEY_KEYPAD_9;
		}

		case XK_F1:
		{
			return KEY_F1;
		}

		case XK_F2:
		{
			return KEY_F2;
		}

		case XK_F3:
		{
			return KEY_F3;
		}

		case XK_F4:
		{
			return KEY_F4;
		}

		case XK_F5:
		{
			return KEY_F5;
		}

		case XK_F6:
		{
			return KEY_F6;
		}

		case XK_F7:
		{
			return KEY_F7;
		}

		case XK_F8:
		{
			return KEY_F8;
		}

		case XK_F9:
		{
			return KEY_F9;
		}

		case XK_F10:
		{
			return KEY_F10;
		}

		case XK_F11:
		{
			return KEY_F11;
		}

		case XK_F12:
		{
			return KEY_F12;
		}

		case XK_Shift_L:
		{
			return KEY_LEFTSHIFT;
		}

		case XK_Shift_R:
		{
			return KEY_RIGHTSHIFT;
		}

		case XK_Control_R:
		{
			return KEY_RIGHTCONTROL;
		}

		case XK_Control_L:
		{
			return KEY_LEFTCONTROL;
		}

		case XK_Caps_Lock:
		{
			return KEY_CAPSLOCK;
		}

		case XK_Alt_L:
		{
			return KEY_LEFTALT;
		}

		case XK_Alt_R:
		{
			return KEY_RIGHTALT;
		}

		default:
		{
			return 0;
		}
		}
	}

	static void Linux_EnableDecorators( window_t* window, GLbitfield decorators )
	{
		if ( decorators & DECORATOR_CLOSEBUTTON )
		{
			window->currentWindowStyle |= LINUX_DECORATOR_CLOSE;
			window->decorators = 1;
		}

		if ( decorators & DECORATOR_MINIMIZEBUTTON )
		{
			window->currentWindowStyle |= LINUX_DECORATOR_MINIMIZE;
			window->decorators = 1;
		}

		if ( decorators & DECORATOR_MAXIMIZEBUTTON )
		{
			window->currentWindowStyle |= LINUX_DECORATOR_MAXIMIZE;
			window->decorators = 1;
		}

		if ( decorators & DECORATOR_ICON )
		{
			//Linux ( at least cinammon ) doesnt have icons in the window. only in the taskbar icon
		}

		//just need to set it to 1 to enable all decorators that include title bar 
		if ( decorators & DECORATOR_TITLEBAR )
		{
			window->decorators = 1;
		}

		if ( decorators & DECORATOR_BORDER )
		{
			window->decorators = 1;
		}

		if ( decorators & DECORATOR_SIZEABLEBORDER )
		{
			window->decorators = 1;
		}

		long hints[ 5 ] = { LINUX_FUNCTION | LINUX_DECORATOR, window->currentWindowStyle, window->decorators, 0, 0 };

		XChangeProperty( GetDisplay(), window->windowHandle, window->AtomHints, XA_ATOM, 32,
			PropModeReplace, ( unsigned char* )hints, 5 );

		XMapWindow( GetDisplay(), window->windowHandle );
	}

	static void Linux_DisableDecorators( window_t* window, GLbitfield decorators )
	{
		if ( decorators & DECORATOR_CLOSEBUTTON )
		{
			//I hate doing this but it is neccessary to keep functionality going.
			bool minimizeEnabled, maximizeEnabled;

			if ( decorators & DECORATOR_MAXIMIZEBUTTON )
			{
				maximizeEnabled = GL_TRUE;
			}

			if ( decorators & DECORATOR_MINIMIZEBUTTON )
			{
				minimizeEnabled = GL_TRUE;
			}

			window->currentWindowStyle &= ~LINUX_DECORATOR_CLOSE;

			if ( maximizeEnabled )
			{
				window->currentWindowStyle |= LINUX_DECORATOR_MAXIMIZE;
			}

			if ( minimizeEnabled )
			{
				window->currentWindowStyle |= LINUX_DECORATOR_MINIMIZE;
			}

			window->decorators = 1;
		}

		if ( decorators & DECORATOR_MINIMIZEBUTTON )
		{
			window->currentWindowStyle &= ~LINUX_DECORATOR_MINIMIZE;
			window->decorators = 1;
		}

		if ( decorators & DECORATOR_MAXIMIZEBUTTON )
		{
			bool minimizeEnabled;

			if ( decorators & DECORATOR_MINIMIZEBUTTON )
			{
				minimizeEnabled = GL_TRUE;
			}

			window->currentWindowStyle &= ~LINUX_DECORATOR_MAXIMIZE;

			if ( minimizeEnabled )
			{
				window->currentWindowStyle |= LINUX_DECORATOR_MINIMIZE;
			}

			window->decorators = 1;
		}

		if ( decorators & DECORATOR_ICON )
		{
			//Linux ( at least cinammon ) doesnt have icons in the window. only in the taskbar icon
		}

		//just need to set it to 1 to enable all decorators that include title bar 
		if ( decorators & DECORATOR_TITLEBAR )
		{
			window->decorators = LINUX_DECORATOR_BORDER;
		}

		if ( decorators & DECORATOR_BORDER )
		{
			window->decorators = 0;
		}

		if ( decorators & DECORATOR_SIZEABLEBORDER )
		{
			window->decorators = 0;
		}

		long hints[ 5 ] = { LINUX_FUNCTION | LINUX_DECORATOR, window->currentWindowStyle, window->decorators, 0, 0 };

		XChangeProperty( GetDisplay(), window->windowHandle, window->AtomHints, XA_ATOM, 32,
			PropModeReplace, ( unsigned char* )hints, 5 );

		XMapWindow( GetDisplay(), window->windowHandle );
	}

	static void Linux_SetWindowStyle( window_t* window, unsigned int windowStyle )
	{
		switch ( windowStyle )
		{
		case WINDOWSTYLE_DEFAULT:
		{
			window->decorators = ( 1L << 2 );
			window->currentWindowStyle = LINUX_DECORATOR_MOVE | LINUX_DECORATOR_CLOSE |
				LINUX_DECORATOR_MAXIMIZE | LINUX_DECORATOR_MINIMIZE;
			long Hints[ 5 ] = { LINUX_FUNCTION | LINUX_DECORATOR, window->currentWindowStyle, window->decorators, 0, 0 };

			XChangeProperty( GetDisplay(), window->windowHandle, window->AtomHints, XA_ATOM, 32, PropModeReplace,
				( unsigned char* )Hints, 5 );

			XMapWindow( GetDisplay(), window->windowHandle );
			break;
		}

		case WINDOWSTYLE_BARE:
		{
			window->decorators = ( 1L << 2 );
			window->currentWindowStyle = ( 1L << 2 );
			long Hints[ 5 ] = { LINUX_FUNCTION | LINUX_DECORATOR, window->currentWindowStyle, window->decorators, 0, 0 };

			XChangeProperty( GetDisplay(), window->windowHandle, window->AtomHints, XA_ATOM, 32, PropModeReplace,
				( unsigned char* )Hints, 5 );

			XMapWindow( GetDisplay(), window->windowHandle );
			break;
		}

		case WINDOWSTYLE_POPUP:
		{
			window->decorators = 0;
			window->currentWindowStyle = ( 1L << 2 );
			long Hints[ 5 ] = { LINUX_FUNCTION | LINUX_DECORATOR, window->currentWindowStyle, window->decorators, 0, 0 };

			XChangeProperty( GetDisplay(), window->windowHandle, window->AtomHints, XA_ATOM, 32, PropModeReplace,
				( unsigned char* )Hints, 5 );

			XMapWindow( GetDisplay(), window->windowHandle );
			break;
		}

		default:
		{
			TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_INVALID_WINDOWSTYLE );
			break;
		}
		}
	}

	static void Linux_SetWindowIcon( window_t* window, const char* icon, unsigned int width, unsigned int height )
	{
		//sorry :( 
		TinyWindow_PrintErrorMessage( TINYWINDOW_ERROR_LINUX_FUNCTION_NOT_IMPLEMENTED );
	}

	static GLXFBConfig GetBestFrameBufferConfig( window_t* givenWindow )
	{
		const int visualAttributes[  ] =
		{
			GLX_X_RENDERABLE, GL_TRUE,
			GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
			GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
			GLX_RED_SIZE, givenWindow->colourBits,
			GLX_GREEN_SIZE, givenWindow->colourBits,
			GLX_BLUE_SIZE, givenWindow->colourBits,
			GLX_ALPHA_SIZE, givenWindow->colourBits,
			GLX_DEPTH_SIZE, givenWindow->depthBits,
			GLX_STENCIL_SIZE, givenWindow->stencilBits,
			GLX_DOUBLEBUFFER, GL_TRUE,
			None
		};

		int frameBufferCount;
		unsigned int bestBufferConfig, bestNumSamples = 0;
		GLXFBConfig* configs = glXChooseFBConfig( GetDisplay(), 0, visualAttributes, &frameBufferCount );

		for ( unsigned int currentConfig = 0; currentConfig < frameBufferCount; currentConfig++ )
		{
			XVisualInfo* visualInfo = glXGetVisualFromFBConfig( GetDisplay(), configs[ currentConfig ] );

			if ( visualInfo )
			{
				//printf( "%i %i %i\n", VisInfo->depth, VisInfo->bits_per_rgb, VisInfo->colormap_size );
				int samples, sampleBuffer;
				glXGetFBConfigAttrib( GetDisplay(), configs[ currentConfig ], GLX_SAMPLE_BUFFERS, &sampleBuffer );
				glXGetFBConfigAttrib( GetDisplay(), configs[ currentConfig ], GLX_SAMPLES, &samples );

				if ( sampleBuffer && samples > -1 )
				{
					bestBufferConfig = currentConfig;
					bestNumSamples = samples;
				}
			}

			XFree( visualInfo );
		}

		GLXFBConfig BestConfig = configs[ bestBufferConfig ];

		XFree( configs );

		return BestConfig;
	}

#endif
};

windowManager* windowManager::instance = nullptr;

#endif