/* See LICENSE file for copyright and license details. */

#define TERMINAL "st"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static char *fonts[]                = { "Iosevka Term:size=14:antialias=true:autohint=true", "Hack-Regular:size=10:antialias=true:autohint=true"  };
static const char dmenufont[]       = "monospace:size=10";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#770000";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class      instance    title       tags mask     isfloating   monitor */
  { "Gimp",     NULL,       NULL,       0,            1,           -1 },
//{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle }, /* stack */
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
/* static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL }; */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
/*modifier                        key        function         argument*/


  TAGKEYS(                        XK_1,                       0)
  TAGKEYS(                        XK_2,                       1)
  TAGKEYS(                        XK_3,                       2)
  TAGKEYS(                        XK_4,                       3)
  TAGKEYS(                        XK_5,                       4)
  TAGKEYS(                        XK_6,                       5)
  TAGKEYS(                        XK_7,                       6)
  TAGKEYS(                        XK_8,                       7)
  TAGKEYS(                        XK_9,                       8)

  { MODKEY,                       XK_Return,  spawn,          {.v = termcmd } },
  { MODKEY|ShiftMask,             XK_Return,  spawn,          SHCMD("kitty") },
  { MODKEY,                       XK_space,   zoom,           {0} },
  { MODKEY|ShiftMask,             XK_space,   togglefloating, {0} },
  { MODKEY,                       XK_Tab,     view,           {0} },
  { MODKEY|ShiftMask,             XK_Tab,     spawn,          SHCMD("") },

  { MODKEY,                       XK_q,       killclient,     {0} },
  { MODKEY|ShiftMask,             XK_q,       quit,           {0} },
  { MODKEY,                       XK_w,       spawn,          SHCMD("firefox") },
  { MODKEY|ShiftMask,             XK_w,       spawn,          SHCMD("google-chrome-stable") },
  { MODKEY,                       XK_e,       spawn,          SHCMD(TERMINAL "-e vim ~/.vim/vimrc") },
  { MODKEY|ShiftMask,             XK_e,       spawn,          SHCMD(TERMINAL "-e vim ~/.vim/snips/tex.snippets") },
  { MODKEY,                       XK_r,       spawn,          SHCMD(TERMINAL "ranger") },
  { MODKEY|ShiftMask,             XK_r,       spawn,          SHCMD(TERMINAL "btop") },
  { MODKEY,                       XK_t,       setlayout,      {.v = &layouts[0]} }, /* tile */
  { MODKEY|ShiftMask,             XK_t,       setlayout,      {.v = &layouts[1]} }, /* monocle */
  { MODKEY,                       XK_y,       setlayout,      {.v = &layouts[2]} }, /* null = floating*/
//{ MODKEY|ShiftMask,             XK_y,       setlayout,      {.v = &layouts[3]} },
  { MODKEY,                       XK_u,       spawn,          SHCMD("") },
  { MODKEY|ShiftMask,             XK_u,       spawn,          SHCMD("") },
  { MODKEY,                       XK_i,       incnmaster,     {.i = +1} },
  { MODKEY|ShiftMask,             XK_i,       incnmaster,     {.i = -1} },
  { MODKEY,                       XK_o,       spawn,          SHCMD("") },
  { MODKEY|ShiftMask,             XK_o,       spawn,          SHCMD("") },
  { MODKEY,                       XK_p,       spawn,          SHCMD("feh --bg-max --randomize ~/.wallpapers/*") },
  { MODKEY|ShiftMask,             XK_p,       spawn,          SHCMD("") },

//{ MODKEY,                       XK_a,       togglegaps,     {0} },  // gaps on/off
  { MODKEY|ShiftMask,             XK_a,       spawn,          SHCMD("") },
//{ MODKEY,                       XK_s,       togglesticky,   {0} },
//{ MODKEY|ShiftMask,             XK_s,       togglesmartgaps,{0} },
  { MODKEY,                       XK_d,       spawn,          SHCMD("rofi -modi drun,run -show drun") },
  { MODKEY|ShiftMask,             XK_d,       spawn,          SHCMD("dmenu_run") },
//{ MODKEY,                       XK_f,       togglefullscr,  {0} },
  { MODKEY,                       XK_f,       setlayout,      {.v = &layouts[2]} }, /* set layout to monocle, use fullscreen patch pls xd */
  { MODKEY|ShiftMask,             XK_f,       spawn,          SHCMD("") },
  { MODKEY,                       XK_g,       spawn,          SHCMD("setxkbmap -option caps:escape fi") },
  { MODKEY|ShiftMask,             XK_g,       spawn,          SHCMD("xmodmap ~/.Xmodmap") },
  { MODKEY|ControlMask,           XK_g,       spawn,          SHCMD("xmodmap ~/.Xmodmap-colemak") },
  { MODKEY,                       XK_h,       setmfact,       {.f = -0.05} },
  { MODKEY|ShiftMask,             XK_h,       spawn,          SHCMD("") },
  { MODKEY,                       XK_j,       focusstack,     {.i = +1} },
  { MODKEY|ShiftMask,             XK_j,       spawn,          SHCMD("") },
  { MODKEY,                       XK_k,       focusstack,     {.i = -1} },
  { MODKEY|ShiftMask,             XK_k,       spawn,          SHCMD("") },
  { MODKEY,                       XK_l,       setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_l,       spawn,          SHCMD("") },

  { MODKEY,                       XK_z,       spawn,          SHCMD("") },
  { MODKEY|ShiftMask,             XK_z,       spawn,          SHCMD("") },
  { MODKEY,                       XK_x,       spawn,          SHCMD("") },
  { MODKEY|ShiftMask,             XK_x,       spawn,          SHCMD("") },
  { MODKEY,                       XK_c,       spawn,          SHCMD(TERMINAL " -e vim ~/.dwm/config.h") },
  { MODKEY|ShiftMask,             XK_c,       spawn,          SHCMD("code") },
  { MODKEY,                       XK_v,       spawn,          SHCMD("") },
  { MODKEY|ShiftMask,             XK_v,       spawn,          SHCMD("") },
  { MODKEY,                       XK_b,       spawn,          SHCMD("~/github/dwmstatus/dwmstatus-restart") },
  { MODKEY|ShiftMask,             XK_b,       togglebar,      {0} },
  { MODKEY,                       XK_n,       spawn,          SHCMD(TERMINAL "-e nmtui") },
  { MODKEY|ShiftMask,             XK_n,       spawn,          SHCMD("") },
  { MODKEY,                       XK_m,       spawn,          SHCMD("autorandr docked; feh --bg-max --randomize ~/.wallpapers/*") },
  { MODKEY|ShiftMask,             XK_m,       spawn,          SHCMD("autorandr mobile; feh --bg-max --randomize ~/.wallpapers/*") },
  { MODKEY|ControlMask,           XK_m,       spawn,          SHCMD("arandr") },
  { MODKEY,                       XK_comma,   spawn,          SHCMD("") },
  { MODKEY|ShiftMask,             XK_comma,   spawn,          SHCMD("") },
  { MODKEY,                       XK_period,  spawn,          SHCMD("") },
  { MODKEY|ShiftMask,             XK_period,  spawn,          SHCMD("") },
//{ MODKEY,                       XK_-,       spawn,          SHCMD("") },
//{ MODKEY|ShiftMask,             XK_-,       spawn,          SHCMD("") },


  { MODKEY,                       XF86XK_AudioMute,   spawn,          SHCMD(TERMINAL " -e pavucontrol") },
  { 0, XF86XK_AudioMute,                              spawn,          SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; ~/.scripts/volumechangenotification.sh") },
  { 0, XF86XK_AudioRaiseVolume,                       spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%; ~/.scripts/volumechangenotification.sh") },
  { 0, XF86XK_AudioLowerVolume,                       spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%; ~/.scripts/volumechangenotification.sh") },
  { 0, XF86XK_AudioMicMute,                           spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },

  { 0, XF86XK_MonBrightnessUp,                        spawn,          SHCMD("xbacklight -inc 10; .scripts/brightnessnotification.sh") },
  { 0, XF86XK_MonBrightnessDown,                      spawn,          SHCMD("xbacklight -dec 10; .scripts/brightnessnotification.sh") },
  { MODKEY, XF86XK_MonBrightnessDown,                 spawn,          SHCMD("xbacklight -set 1; .scripts/brightnessnotification.sh") },

  { 0, XK_Print,                                      spawn,          SHCMD("shotgun -s -f png /home/martti/Downloads/`date --iso-8601=seconds`.png; dunstify 'test' 'taking a screenshot'")}



};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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
