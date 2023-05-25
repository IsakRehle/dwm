ESELECT(1)                                                                   eselect                                                                   ESELECT(1)

NAME
       eselect - Gentoo's multi-purpose configuration and management tool

SYNOPSIS
       eselect [global options] module [action]

DESCRIPTION
       eselect is Gentoo's configuration and management tool.  It features modules that care for individual administrative tasks.

OPTIONS
       --brief
              Set brief output mode, for use as input to other programs.  (This is an experimental feature.)

       --color=mode, --colour=mode
              Enable or disable colour output.  mode can be yes, no, or auto.  The default is auto, for which colour output is enabled only if standard output is
              connected to a terminal.

       --root=path
              The path that eselect should use as the target root filesystem for its operations.  If not specified, the value of the ROOT environment variable is
              used as a default.

BUILT-INS
       help   Displays a help screen listing all built-ins and the installed modules.

       usage  Displays a minimal help screen.

       version
              Prints eselect's version tag.

MODULES
       You can view a list of installed modules using

              eselect modules list

       For individual help on each module, please run

              eselect module help

       or refer to the manpage module.eselect(5).

FULL DOCUMENTATION
       Full user and developer documentation is included in Restructured Text (RST) format.  The 'html' Make target can be used to generate HTML versions.

AUTHORS
       Danny van Dyk <kugelfang@gentoo.org>
       Ciaran McCreesh <ciaranm@gentoo.org>
       Aaron Walker <ka0ttic@gentoo.org>
       Ulrich Müller <ulm@gentoo.org>

Gentoo Linux                                                               January 2022                                                                ESELECT(1)
