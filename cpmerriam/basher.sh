
set -v
echo "This line will be printed verbosely"
set +v

(set -x; echo cat)
(set -v; echo cat)
