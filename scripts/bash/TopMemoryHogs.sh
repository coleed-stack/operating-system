#!/bin/bash

ps -eo pid,%mem,cmd --sort=-%mem | head -n 6
