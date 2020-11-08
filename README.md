wd_book
=============

Computer science book about Wikidata programming.

[Petrozavodsk State University](https://en.wikipedia.org/wiki/Petrozavodsk_State_University) (PetrSU), Internet-mathematics course.


# Wikidata programming book (in English)

See our course [Research in programming Wikidata](https://en.wikiversity.org/wiki/Research_in_programming_Wikidata) in English Wikiversity.

We are using the LaTeX template [https://github.com/fmarotta/kaobook fmarotta / kaobook].
Read [the template tutorial online](https://github.com/fmarotta/kaobook/blob/master/examples/documentation/main_with_bibtex.pdf).

## Quick Start

The Wikidata book in English (file `wd_book/en/mainka.tex`) can be compiled with the following:

    pdflatex mainka # Compile template
    makeindex mainka.nlo -s nomencl.ist -o mainka.nls # Compile nomenclature
    makeindex mainka # Compile index
    biber mainka # Compile bibliography
    makeglossaries main # Compile glossary
    pdflatex mainka # Compile template again
    pdflatex mainka # Compile template again

The result should look like `mainka.pdf`.

# Wikidata programming book (in Russian)

See our course [Research in programming Wikidata](https://ru.wikiversity.org/wiki/Программирование_Викиданных) in Russian Wikiversity.

## Quick Start

The Wikidata book in Russian (file `wd_book/ru/wd_book.tex`) can be compiled with the following:

    pdflatex wd_book_ru
    bibtex wd_book_ru
    makeindex wd_book_ru.idx
    # or texindy --language english wd_book.idx
    pdflatex wd_book_ru
    pdflatex wd_book_ru
    pdflatex wd_book_ru

The result should look like `wd_book_ru.pdf`.

## Troubleshooting

If you encounter errors of the form,

    ! LaTeX Error: File `paralist.sty' not found.

you will need to obtain missing packages from [CTAN](http://ctan.org).
For package installation instructions and answers to many other
questions, see the [UK TeX FAQ](http://www.tex.ac.uk/faq/) or search the [`comp.text.tex` group](http://groups.google.com/group/comp.text.tex).

The template of [Tufte-LaTeX](https://github.com/Tufte-LaTeX/tufte-latex) GitHub project used.

# Literature

   * Krizhanovsky, Andrew (2015) [Methodology and guidelines of writing articles in Wikipedia by students with the help of the teacher (the Russian Wikipedia case study)](http://nauchkor.ru/pubs/rabota-v-viki-srede-na-primere-russkoy-vikipedii-5690f7f35f1be74d9400018e) (in Russian). Petrozavodsk. (preprint). 
.
