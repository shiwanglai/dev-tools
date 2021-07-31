#
# Makefile for build and display
#

#
# definitions
svgs_dir := svgs

PHONY := demo

demo: $(svgs_dir)/demo.svg

#
# common rules
$(svgs_dir)/%.svg: %.dot
	dot $< -Tsvg -o $@
	display $@ &

.PHONY: $(PHONY)
