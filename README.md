wd_book
=============

Computer science book about Wikidata programming.

[Petrozavodsk State University](https://en.wikipedia.org/wiki/Petrozavodsk_State_University) (PetrSU), Internet-mathematics course.

See the latest Russian and English PDF files at [https://bit.ly/3lVumoT](https://www.dropbox.com/sh/0ujam53seriygmg/AAA83UtcAA5dCL2LpQ4ueOQGa).


# Wikidata programming book (in English)

See our course [Research in programming Wikidata](https://en.wikiversity.org/wiki/Research_in_programming_Wikidata) in English Wikiversity.

We are using the LaTeX template [fmarotta/kaobook](https://github.com/fmarotta/kaobook).
Read [the template tutorial online](https://github.com/fmarotta/kaobook/blob/master/examples/documentation/main.pdf).

The Wikidata book in English (file `wd_book/en/mainka.tex`) can be compiled with the following:

    pdflatex mainka # Compile template
    makeindex mainka.nlo -s nomencl.ist -o mainka.nls # Compile nomenclature
    makeindex mainka # Compile index
    bibtex mainka # Compile bibliography
    makeglossaries mainka # Compile glossary (install xindy)
    pdflatex mainka # Compile template again
    pdflatex mainka # and again

The result should look like `mainka.pdf`.

# Wikidata programming book (in Russian)

See our course [Research in programming Wikidata](https://ru.wikiversity.org/wiki/Программирование_Викиданных) in Russian Wikiversity.

We are using the LaTeX template [Tufte-LaTeX](https://github.com/Tufte-LaTeX/tufte-latex).
Read [the template tutorial online](https://raw.githubusercontent.com/Tufte-LaTeX/tufte-latex/master/sample-book.pdf).

The Wikidata book in Russian (file `wd_book/ru/wd_book.tex`) can be compiled with the following:

    pdflatex wd_book_ru
    biber wd_book_ru
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
