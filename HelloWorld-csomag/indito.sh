#!/bin/bash
# Megkeressük, hogy fizikailag hol van ez a mappa a rendszerben
DIR="$(cd "$(dirname "${BASH_SOURCE}")" && pwd)"

# Kényszerítjük a Linuxot, hogy EBBŐL a mappából olvassa a .so fájlokat, ne a rendszerből
export LD_LIBRARY_PATH="$DIR:$LD_LIBRARY_PATH"

# Elindítjuk a programot, átadva neki az összes indítási argumentumot
exec "$DIR/HelloWorldConsole" "$@"
