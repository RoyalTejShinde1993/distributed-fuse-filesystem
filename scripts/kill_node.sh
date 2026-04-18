
#!/bin/bash
PORT=$1
pkill -f $PORT
echo "Killed node on port $PORT"
