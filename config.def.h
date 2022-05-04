/* frankfut's build of dwm
*  feel free to fork/use it
*  inspired on siduck's chadwm
*/

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 8;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;        /* vert inner gap between windows */
static const unsigned int gappoh    = 8;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;        /* vert outer gap between windows and screen edge */
static const unsigned int colorfultag = 1;  	/* 0 means use SchemeSel for selected tag */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int horizpadbar        = 0;        /* horizontal padding for statusbar */
static const int vertpadbar         = 8;        /* vertical padding for statusbar */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
#define ICONSIZE 16   /* icon size */
#define ICONSPACING 5 /* space between icon and title */
static const int vertpad            = 0;        /* vertical padding of bar */
static const int sidepad            = 0;        /* horizontal padding of bar */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono Medium:style=Medium,Regular:size=10:antialias=true:autohint=true",
					"Symbols Nerd Font Mono:style=2048-em:pixelsize=14:antialias=true:autohint=true",
					"Material Design Icons:style=Regular:pixelsize=15:antialias=true:autohint=true",
					"JoyPixels:style=Regular:size=10:antialias=true:autohint=true", 
					"Takaoゴシック:style=Regular:size=12:antialias=true:autohint=true" };
/* colors */
#include "themes/catppuccin.h"

/* tagging */
static const char *tags[]     = { "ﭾ", "", "", "", "" };
static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5 };

/* underline tags */
static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* client rules */
static const char systray_app_class[] = "trayer";
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "trayer",  NULL,     NULL,           0,         0,          0,           1,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 4,    0,          0,           0,        -1 },
	{ "st",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] 		= { "dmenu_run", NULL };
static const char *powermenu[] 		= { "/home/frankfut/.local/bin/dmenu-powermenu", NULL };
static const char *watchmedia[] 	= { "/home/frankfut/.local/bin/dmenu-watchmedia", NULL };

/* keybinds */
static Key keys[] = {
		// shell commmands
	{ MODKEY|ShiftMask,		XK_minus,  spawn,	   SHCMD("pamixer --allow-boost -d 5 && kill -37 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_equal,  spawn,	   SHCMD("pamixer --allow-boost -i 5 && kill -37 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_m,	   spawn,	   SHCMD("pamixer -t && kill -37 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_w, 	   spawn,	   SHCMD("firefox") },
	{ MODKEY|ShiftMask,		XK_x,	   spawn,	   SHCMD("st -e htop") },
	{ MODKEY|ShiftMask,		XK_l,	   spawn,	   SHCMD("slock") },
	{ MODKEY,			XK_s,	   spawn,	   SHCMD("pkill trayer || trayer --width 100 --edge top --align right --expand true --SetDockType true --tint 0x161320 --transparent true --alpha 0 --height 28 --padding 3") },
	{ MODKEY,			XK_m,	   spawn,	   SHCMD("st -e ncmpcpp") },
	{ MODKEY,			XK_Return, spawn,	   SHCMD("st") },
	{ 0,				XK_Print,  spawn,	   SHCMD("scrot '~/pix/scrots/%d-%m-%Y-%H:%M:%S_$wx%h.png' -e 'xclip -selection clipboard -target image/png -i $f'") },
	{ ShiftMask,			XK_Print,  spawn,	   SHCMD("scrot --select --line mode=edge '~/pix/scrots/%d-%m-%Y-%H:%M:%S_$wx%h.png' -e 'xclip -selection clipboard -target image/png -i $f'") },
	{ MODKEY,			XK_Print,  spawn,	   SHCMD("scrot -u '~/pix/scrots/%d-%m-%Y-%H:%M:%S_$wx%h.png' -e 'xclip -selection clipboard -target image/png -i $f'") },

		// custom scripts
	{ MODKEY,			XK_BackSpace, spawn,	   {.v = powermenu } },
	{ MODKEY|ShiftMask,		XK_v,	   spawn,	   {.v = watchmedia } },
	{ MODKEY,                       XK_c,      spawn,          {.v = dmenucmd } },
		// move things around
	{ MODKEY,			XK_Left,   shiftview,	   {.i = -1 } },
	{ MODKEY,			XK_Right,  shiftview,	   {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
		// *facts
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,           XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ControlMask,           XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ControlMask,           XK_o,      setcfact,       {.f =  0.00} },
		// gaps
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
		// layouts
	{ MODKEY|ControlMask,           XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ControlMask,		XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
		// misc
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,  	                XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
		// change tags
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
		// quit/restart dwm
	{ MODKEY|ControlMask,           XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,      	Button2,        spawn,	        SHCMD("st") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

