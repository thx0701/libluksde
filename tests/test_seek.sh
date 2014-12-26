#!/bin/bash
#
# Library seek testing script
#
# Copyright (c) 2013-2014, Joachim Metz <joachim.metz@gmail.com>
#
# Refer to AUTHORS for acknowledgements.
#
# This software is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this software.  If not, see <http://www.gnu.org/licenses/>.
#

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

list_contains()
{
	LIST=$1;
	SEARCH=$2;

	for LINE in $LIST;
	do
		if test $LINE = $SEARCH;
		then
			return ${EXIT_SUCCESS};
		fi
	done

	return ${EXIT_FAILURE};
}

test_seek()
{ 
	echo "Testing seek offset of input:" $*;

	rm -rf tmp;
	mkdir tmp;

	${TEST_RUNNER} ./${LUKSDE_TEST_SEEK} $*;

	RESULT=$?;

	rm -rf tmp;

	echo "";

	return ${RESULT};
}

test_seek_password()
{ 
	DIRNAME=$1;
	INPUT_FILE=$2;
	BASENAME=`basename ${INPUT_FILE}`;
	RESULT=${EXIT_FAILURE};
	PASSWORD_FILE="input/.libluksde/${DIRNAME}/${BASENAME}.password";

	if test -f "${PASSWORD_FILE}";
	then
		rm -rf tmp;
		mkdir tmp;

		PASSWORD=`cat "${PASSWORD_FILE}" | head -n 1 | sed 's/[\r\n]*$//'`;

		echo "Testing seek with password of input: ${INPUT_FILE}";

		${TEST_RUNNER} ./${LUKSDE_TEST_SEEK} -p${PASSWORD} ${INPUT_FILE};

		RESULT=$?;

		rm -rf tmp;

		echo "";
	else
		echo "Testing seek with password of input: ${INPUT_FILE} (FAIL)";
	fi

	return ${RESULT};
}

LUKSDE_TEST_SEEK="luksde_test_seek";

if ! test -x ${LUKSDE_TEST_SEEK};
then
	LUKSDE_TEST_SEEK="luksde_test_seek.exe";
fi

if ! test -x ${LUKSDE_TEST_SEEK};
then
	echo "Missing executable: ${LUKSDE_TEST_SEEK}";

	exit ${EXIT_FAILURE};
fi

TEST_RUNNER="tests/test_runner.sh";

if ! test -x ${TEST_RUNNER};
then
	TEST_RUNNER="./test_runner.sh";
fi

if ! test -x ${TEST_RUNNER};
then
	echo "Missing test runner: ${TEST_RUNNER}";

	exit ${EXIT_FAILURE};
fi

if ! test -d "input";
then
	echo "No input directory found.";

	exit ${EXIT_IGNORE};
fi

OLDIFS=${IFS};
IFS="
";

RESULT=`ls input/* | tr ' ' '\n' | wc -l`;

if test ${RESULT} -eq 0;
then
	echo "No files or directories found in the input directory.";

	EXIT_RESULT=${EXIT_IGNORE};
else
	IGNORELIST="";

	if test -f "input/.libluksde/ignore";
	then
		IGNORELIST=`cat input/.libluksde/ignore | sed '/^#/d'`;
	fi
	for TESTDIR in input/*;
	do
		if test -d "${TESTDIR}";
		then
			DIRNAME=`basename ${TESTDIR}`;

			if ! list_contains "${IGNORELIST}" "${DIRNAME}";
			then
				if test -f "input/.libluksde/${DIRNAME}/files";
				then
					TEST_FILES=`cat input/.libluksde/${DIRNAME}/files | sed "s?^?${TESTDIR}/?"`;
				else
					TEST_FILES=`ls -1 ${TESTDIR}/* 2> /dev/null`;
				fi
				for TEST_FILE in ${TEST_FILES};
				do
					if test -f "input/.libluksde/${DIRNAME}/${BASENAME}.password";
					then
						if ! test_seek_password "${DIRNAME}" "${TEST_FILE}";
						then
							exit ${EXIT_FAILURE};
						fi
					else
						if ! test_seek "${TEST_FILE}";
						then
							exit ${EXIT_FAILURE};
						fi
					fi
				done
			fi
		fi
	done

	EXIT_RESULT=${EXIT_SUCCESS};
fi

IFS=${OLDIFS};

exit ${EXIT_RESULT};
