# ------------------------------------------------------------------------------
# Makefile for documentation build
# SPDX-License-Identifier: Apache-2.0

BUILDDIR ?= _build
DOC_TAG ?= development
<<<<<<< HEAD
SPHINXOPTS ?= -j auto
=======
SPHINXOPTS ?= -j auto -W --keep-going -T
SPHINXOPTS_EXTRA ?=
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
LATEXMKOPTS ?= -halt-on-error -no-shell-escape
DT_TURBO_MODE ?= 0

# ------------------------------------------------------------------------------
# Documentation targets

.PHONY: configure clean html html-fast latex pdf doxygen

html-fast:
	${MAKE} html DT_TURBO_MODE=1

html latex pdf linkcheck doxygen: configure
	cmake --build ${BUILDDIR} --target $@

configure:
	cmake \
		-GNinja \
		-B${BUILDDIR} \
		-S. \
		-DDOC_TAG=${DOC_TAG} \
		-DSPHINXOPTS="${SPHINXOPTS}" \
<<<<<<< HEAD
=======
		-DSPHINXOPTS_EXTRA="${SPHINXOPTS_EXTRA}" \
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		-DLATEXMKOPTS="${LATEXMKOPTS}" \
		-DDT_TURBO_MODE=${DT_TURBO_MODE}

clean:
	cmake --build ${BUILDDIR} --target clean
