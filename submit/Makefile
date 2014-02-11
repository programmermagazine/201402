all : textMining.html

%.html : %.md
	Rscript -e "library(markdown);markdownToHTML('$<', '$@')"

%.md : %.Rmd
	Rscript -e "library(knitr);knit('$<', '$@')"