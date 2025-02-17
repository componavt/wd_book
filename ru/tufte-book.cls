\NeedsTeXFormat{LaTeX2e}[1994/06/01]

\ProvidesClass{tufte-book}[2015/06/30 v3.5.3 Tufte-book class]

%%
% Declare we're tufte-book
\newcommand{\@tufte@class}{book}% the base LaTeX class (defaults to the article/handout style)
\newcommand{\@tufte@pkgname}{tufte-book}% the name of the package (defaults to tufte-handout)

%%
% Load the common style elements
\input{tufte-common.def}


%%
% Set up any book-specific stuff now

%%
% The front matter in Tufte's /Beautiful Evidence/ contains everything up
% to the opening page of Chapter 1.  The running heads, when they appear,
% contain only the (arabic) page number in the outside corner.
%\newif\if@mainmatter \@mainmattertrue
\renewcommand\frontmatter{%
  \if@openright%
    \cleardoublepage%
  \else%
    \clearpage%
  \fi%
  \@mainmatterfalse%
  \pagenumbering{arabic}%
  %\pagestyle{plain}%
  \fancyhf{}%
  \ifthenelse{\boolean{@tufte@twoside}}%
    {\fancyhead[LE,RO]{\thepage}}%
    {\fancyhead[RE,RO]{\thepage}}%
}

\fancyfoot[REF,ROF]{\thepage}% page number in first pages - Footer Right - Contents, Acknowledgement and Preface pages, before Part 1

%%
% The main matter in Tufte's /Beautiful Evidence/ doesn't restart the page
% numbering---it continues where it left off in the front matter.
\renewcommand\mainmatter{%
  \if@openright%
    \cleardoublepage%
  \else%
    \clearpage%
  \fi%
  \@mainmattertrue%
  \fancyhf{}%
  \ifthenelse{\boolean{@tufte@twoside}}%
    {% two-side
      \renewcommand{\chaptermark}[1]{\markboth{##1}{}}%
%%%      \fancyhead[LE]{\thepage\quad\newlinetospace{\plaintitle}}% book title
%%%      \fancyhead[RO]{\newlinetospace{\leftmark}\quad\thepage}% chapter title
      \fancyhead[RO]{1xxxx\newlinetospace{\leftmark}}% chapter title without page number - only right page
      \fancyfoot[REF,ROF]{2yyyy\thepage}

    }%
    {% one-side

% italics{ Chapter N. Title of the chapter } in the upper right corner of the sheet 
\pagestyle{fancy}
\fancyhead{}
% \fancyhead[RE,RO]{\newlinetospace{\nouppercase{77777 \leftmark}}}% chapter title without page number - top right page corner
%\fancyhead[RE,RO]{\newlinetospace{\nouppercase{\fontfamily{droidserif}\selectfont\underline{\leftmark}}}}
\fancyhead[RE,RO]{\nouppercase{\fontfamily{iwona}\selectfont\textit{\leftmark}}}
% kurier - без засечек, оригинально - телеграфный шрифт. 
% iwona - аккуратный чертёжный шрифт 
% droidserif - little bold

      \fancyfoot[REF,ROF]{\thepage}% page number everywhere - Footer Right
    }%
}


%%
% The back matter contains appendices, indices, glossaries, endnotes,
% biliographies, list of contributors, illustration credits, etc.
\renewcommand\backmatter{%
  \if@openright%
    %\clearpage%    \cleardoublepage%
  \else%
    %\clearpage%
  \fi%
  \@mainmatterfalse%
}

%%
% Only show the chapter titles in the table of contents
\setcounter{tocdepth}{1}

%%
% If there is a `tufte-book-local.sty' file, load it.

\IfFileExists{tufte-book-local.tex}{%
  \@tufte@info@noline{Loading tufte-book-local.tex}%
  \input{tufte-book-local}%
}{}

%%
% End of file
\endinput
