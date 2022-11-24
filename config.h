/* See LICENSE file for copyright and license details. */
/* #define TERMINAL "st" */

/* Appearance */
static const unsigned int borderpx  = 1;        /* border pixel size of windows */
static const unsigned int gappx     = 5;        /* gaps size between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=12", "fontawesome:size=12" };
static const char dmenufont[]       = "monospace:size=12";
/* Background color */
static const char col_gray1[]       = "#222222";
/* Inactive window border color */
static const char col_gray2[]       = "#444444";
/*  font color  */
static const char col_gray3[]       = "#bbbbbb"
/* Current tag and current window font color */
static const char col_gray4[]       = "#eeeeee";
/* Top bar second color (blue) and active window border color */
static const char col_select[]        = "#f59542";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, "#54487a", col_select },
	//[SchemeSel]  = { col_gray4, col_select,  col_select  },
};

/* tagging */
//tag names (upper left)
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ NULL,       NULL,       NULL,       0,            0,           -1 },
	/* { "firefox",  NULL,       NULL,       1 << 8,       0,           -1 }, */
	/* { "mpv",      NULL,       NULL,       1 << 7,       0,           -1 }, */
};

/* Layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* #define STACKKEYS(MOD,ACTION) \ */
/* 	{ MOD,	                        XK_j,	ACTION##stack,	{.i = INC(+1) } }, \ */
/* 	{ MOD,	                        XK_k,	ACTION##stack,	{.i = INC(-1) } }, \ */
/* 	{ MOD,                          XK_v,   ACTION##stack,  {.i = 0 } }, \ */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", "#54487a", "-sf", col_gray4, NULL };

/* Default terminal */
static const char *termcmd[]  = { "st", NULL };

/* Volume controls */
static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *mutevol[] = { "amixer", "-q", "set", "Master", "toggle", NULL };

/* Shortcuts */
static const char *filemanager[] = { "st", "lfub", NULL };
static const char *mailcmd[] = { "st", "neomutt", NULL };
static const char *topcmd[]  = { "st", "htop", NULL };

#include "shiftview.c"
static char *endx[] = { "/bin/sh", "-c", "endx", "externalpipe", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,	            XK_d,	   spawn,		   SHCMD("passmenu") },
	{ MODKEY,	                    XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,	            XK_Return, spawn,          {.v = filemanager } },
	{ MODKEY,	                    XK_p,	   spawn,		   SHCMD("passmenu") },
	{ MODKEY|ShiftMask,	            XK_w,	   spawn,		   SHCMD("$BROWSER") },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,	                    XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_z,	   zoom,           {0} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,              		    XK_n,      shiftview,  	   { .i = +1 } },
	{ MODKEY,              		    XK_b,      shiftview,      { .i = -1 } },
    { MODKEY,                       XK_z,      setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_x,      setgaps,        {.i = +5 } },
    { MODKEY,                       XK_equal,  spawn,          {.v = upvol   } },
    { MODKEY,                       XK_minus,  spawn,          {.v = downvol } },
    { MODKEY,                       XK_m,      spawn,          {.v = mutevol } },
	{ MODKEY,                       XK_Tab,    focusmon,       {0} },
	{ MODKEY|ShiftMask,             XK_Tab,    tagmon,         {0} },
	{ MODKEY|ShiftMask,             XK_Tab,    focusmon,       {0} },
	{ MODKEY,                       XK_e,      spawn,          {.v = mailcmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = filemanager } },
	{ MODKEY|ShiftMask,	            XK_r,      spawn,          {.v = topcmd } },
	{ MODKEY|ShiftMask,			    XK_n,	   spawn,		   SHCMD("st -e nvim -c VimwikiIndex") },
	{ MODKEY|ShiftMask,			    XK_e,	   spawn,		   SHCMD("st -e watch -p -t -n .5 'grep MHz /proc/cpuinfo'") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

