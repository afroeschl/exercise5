# Hausübung 5 (2 Punkte)

**Ausgabe**: Dienstag 08. April, vormittags. 

**Abgabe bis**: Montag 5. Mai, Ende des Tages.

**Abgabe via**: git-Repository mit dem Namen **`exercise5`** auf unserem git-Server https://sgit.iue.tuwien.ac.at

Details zum Abgabeprozess via `git` finden Sie hier: https://sgit.iue.tuwien.ac.at/360062/git

Wichtig: Sie benötigen ein `recursive`-clone, da dieses Repo git-Submodule enthält:

```
# create your own fork as ususal (example https://sgit.iue.tuwien.ac.at/eXXXXXXXX/exercise5)
git config --global credential.helper "cache --timeout 300"
git clone --recursive https://sgit.iue.tuwien.ac.at/eXXXXXXXX/exercise5.git
```


# Aufgabenstellung

In dieser Hausübung werden folgende Themen erstmalig einfliessen:

- Arbeiten mit Kollektionen von eindeutig Werten `std::set<int>`/`std::unordered_set<int>` 
- Arbeit mit der öffentlichen Schnittstelle einer gegebenen Klasse
- Nutzung von selbst implementierter Funktionalität in einem separaten Anwendungskontext

**Die genaue Beschreibung und Anforderungen finden Sie in [`main.ipynb`](main.ipynb) und im Quellcode.**
