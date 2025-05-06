msg=$1
total=$2
current=$3
color_start=$4
width=60
filled_char='█'
empty_char=' '
color_end='\033[0m'

percentage=$((current * 100 / total))
filled_length=$((percentage * width / 100))
empty_length=$((width - filled_length))

filled=$(printf "%${filled_length}s" | tr ' ' "$filled_char")
empty=$(printf "%${empty_length}s" | tr ' ' "$empty_char")

output="\r$msg[$color_start${filled}${color_end}${empty}] ${percentage}%"
echo -ne "$output"

if [[ "$current" -eq "$total" ]]; then
	echo ""
fi
