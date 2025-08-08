#!/bin/bash

SERVER=./server
CLIENT=./client

if [ ! -x "$SERVER" ] || [ ! -x "$CLIENT" ]; then
  echo "Error: server or client executable not found or not executable"
  exit 1
fi

$SERVER &
SERVER_PID=$!
sleep 1

echo "Server started with PID $SERVER_PID"

test_msg() {
  local msg="$1"
  echo -n "Testing message: "
  echo "$msg" | head -c 30
  echo

  "$CLIENT" "$SERVER_PID" "$msg"
  if [ $? -ne 0 ]; then
    echo "Client failed to send message"
    kill $SERVER_PID
    exit 1
  fi
}

test_msg "Hello, Minitalk!"
test_msg "This is a test! @#&*()_-+=~\`"
test_msg "🚀✨ Unicode test: 你好, мир, hello!"

long_msg=$(head -c 10000 /dev/urandom | base64)
test_msg "$long_msg"

kill $SERVER_PID
wait $SERVER_PID 2>/dev/null

echo "All tests done."
