#! /bin/sh
# https://github.com/jrfonseca/gprof2dot
#

gprofdot_path=/opt/gprof2dot

# compile fookay bin
gcc -pg -g fookay.c -o fookay

# run fookay once to create gmon.out
./fookay

# gprof
gprof ./fookay > tmp_gprof.txt

# gprof2dot
${gprofdot_path}/gprof2dot.py tmp_gprof.txt > tmp_call_graph.dot

# dot
dot -Tsvg tmp_call_graph.dot -o fookay.svg

# clean
rm -rf tmp_*
rm -rf gmon.out

