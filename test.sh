./filler_vm -f maps/map00 -p1 ./players/carli.filler -p2 ./filler > testing
NUM1=$(grep "== O fin: "  testing | awk '{print $4}')
NUM2=$(grep "== X fin: "  testing | awk '{print $4}')
if [ "$NUM1" -gt "$NUM2" ]; then
echo "Player 1 Won"
else
echo "Player 2 Won"
fi
