# Push_swap

*Ce projet a été créé dans le cadre du cursus 42 par mkacemi42 et hhamidi42.*

## Description

Push_swap est un projet d'algorithmique qui consiste à trier des données sur une pile avec un ensemble limité d'instructions, en utilisant le nombre minimal d'actions possible. Le défi réside dans la manipulation de deux piles (a et b) avec seulement 11 opérations autorisées.

L'objectif est de développer un programme en C nommé `push_swap` qui calcule et affiche la séquence d'opérations la plus courte pour trier une liste d'entiers donnée en arguments.

Ce projet impose l'implémentation de **quatre stratégies de tri distinctes** avec des complexités algorithmiques différentes, ainsi qu'un système adaptatif capable de sélectionner la meilleure stratégie en fonction du désordre initial des données.

## Instructions

### Compilation

```bash
make
```

Cela génère l'exécutable `push_swap`.

### Compilation du bonus (checker)

```bash
make bonus
```

Cela génère l'exécutable `checker`.

### Nettoyage

```bash
make clean   # Supprime les fichiers objets
make fclean  # Supprime les fichiers objets et les exécutables
make re      # Recompile complètement le projet
```

### Utilisation

#### Utilisation basique (mode adaptatif par défaut)

```bash
./push_swap 2 1 3 6 5 8
```

#### Forcer une stratégie spécifique

```bash
./push_swap --simple 5 4 3 2 1      # Force l'algorithme O(n²)
./push_swap --medium 4 67 3 87 23   # Force l'algorithme O(n√n)
./push_swap --complex 9 8 7 6 5     # Force l'algorithme O(n log n)
./push_swap --adaptive 4 67 3 87 23 # Mode adaptatif (par défaut)
```

#### Mode benchmark

```bash
./push_swap --bench 4 67 3 87 23
```

Affiche sur stderr :
- Le taux de désordre (%)
- La stratégie utilisée et sa classe de complexité
- Le nombre total d'opérations
- Le décompte par type d'opération (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)

#### Vérification avec le checker (bonus)

```bash
./push_swap 3 2 1 0 | ./checker 3 2 1 0
```

Le checker affiche `OK` si la pile est triée, `KO` sinon.

#### Tests de performance

```bash
# Générer 100 nombres aléatoires et compter les opérations
ARG=$(shuf -i 0-999 -n 100); ./push_swap $ARG | wc -l

# Générer 500 nombres aléatoires et compter les opérations
ARG=$(shuf -i 0-9999 -n 500); ./push_swap $ARG | wc -l
```

## Algorithmes implémentés

### 1. Algorithme Simple : Min/Max Extraction - O(n²)

**Principe :** Cet algorithme extrait itérativement le minimum ou le maximum de la pile a vers la pile b, puis reconstruit la pile a de manière triée.

**Fonctionnement :**
1. Rechercher le plus petit élément dans la pile a
2. Le déplacer au sommet avec des rotations (ra/rra)
3. Le pousser vers la pile b (pb)
4. Répéter jusqu'à ce que la pile a soit vide
5. Repousser tous les éléments de b vers a (pa)

**Complexité :**
- Temps : O(n²) - pour chaque élément, on parcourt potentiellement toute la pile
- Espace : O(1) - utilisation constante de la pile b
- Opérations push_swap : ~n² dans le pire cas

**Justification du choix :**
Simple à implémenter et à comprendre, cet algorithme sert de baseline. Il est efficace pour de très petites entrées (< 10 éléments) où sa simplicité compense sa complexité quadratique.

### 2. Algorithme Medium : Chunk-Based Sorting - O(n√n)

**Principe :** Division de l'ensemble des nombres en √n chunks (groupes) de taille √n, puis tri par chunks successifs.

**Fonctionnement :**
1. Calculer √n et diviser la plage de valeurs en √n intervalles
2. Pour chaque chunk (du plus petit au plus grand) :
   - Identifier tous les éléments appartenant au chunk actuel
   - Les pousser vers la pile b tout en maintenant un ordre relatif
3. Une fois tous les éléments en b, les repousser vers a dans l'ordre :
   - Trouver le maximum dans b
   - Le ramener au sommet (rb/rrb)
   - Le pousser vers a (pa)

**Complexité :**
- Temps : O(n√n) - √n chunks × O(n) opérations par chunk
- Espace : O(1) - utilisation de la pile b uniquement
- Opérations push_swap : ~n√n

**Justification du choix :**
Excellent compromis entre simplicité et performance pour des entrées moyennes (50-200 éléments). Plus rapide que O(n²) tout en restant conceptuellement accessible.

### 3. Algorithme Complex : Radix Sort (LSD) - O(n log n)

**Principe :** Tri par base en traitant les nombres bit par bit, de la position la moins significative (Least Significant Digit) à la plus significative.

**Fonctionnement :**
1. Normaliser les nombres en indices positifs (0 à n-1)
2. Pour chaque bit (du LSB au MSB) :
   - Parcourir la pile a
   - Si le bit est 0, laisser l'élément en a (ra)
   - Si le bit est 1, pousser l'élément vers b (pb)
3. Une fois tous les éléments traités pour ce bit :
   - Repousser tous les éléments de b vers a (pa)
4. Répéter pour chaque bit jusqu'à log₂(n) bits

**Complexité :**
- Temps : O(n log n) - n éléments × log₂(n) bits
- Espace : O(1) - utilisation de la pile b
- Opérations push_swap : ~n × log₂(n) × 2 (pb puis pa par bit)

**Justification du choix :**
Le radix sort est particulièrement adapté aux entiers et exploite leur représentation binaire. Il offre une complexité linéarisable O(n × k) où k = log₂(n), ce qui le rend très performant pour de grandes entrées (500+ éléments). Contrairement aux algorithmes de comparaison (quicksort, mergesort), il ne dépend pas de la distribution des données.

### 4. Algorithme Adaptatif : Sélection dynamique

**Principe :** Mesurer le désordre initial de la pile et sélectionner automatiquement l'algorithme le plus adapté.

**Métrique de désordre :**
Le désordre est calculé en comparant toutes les paires d'éléments :
```
désordre = (nombre de paires inversées) / (nombre total de paires)
```
où une paire (a[i], a[j]) est inversée si i < j mais a[i] > a[j].

**Seuils de sélection :**

| Désordre | Stratégie | Complexité | Justification |
|----------|-----------|------------|---------------|
| < 0.2 (faible) | Optimisation O(n) | O(n) | Pile quasi-triée → corrections locales suffisent |
| 0.2 - 0.5 (moyen) | Chunk-based | O(n√n) | Désordre modéré → chunks adaptés |
| ≥ 0.5 (élevé) | Radix sort | O(n log n) | Désordre fort → tri général optimal |

**Techniques pour désordre faible (< 0.2) :**
- Détection des sous-séquences déjà triées
- Rotations intelligentes pour positionner les éléments mal placés
- Petits swaps locaux (sa, sb, ss)
- Éviter les transferts massifs vers la pile b

**Justification du choix adaptatif :**
L'analyse du désordre permet d'exploiter la structure partielle des données. Une pile presque triée ne nécessite pas un tri complet, tandis qu'une pile très désordonnée bénéficie d'un algorithme robuste comme le radix sort. Cette approche adaptive optimise les performances moyennes sur des entrées réelles.

## Objectifs de performance

### Pour 100 nombres aléatoires :
- ✅ **< 2000 opérations** : validation minimale
- ⭐ **< 1500 opérations** : bonne performance
- 🏆 **< 700 opérations** : performance excellente

### Pour 500 nombres aléatoires :
- ✅ **< 12000 opérations** : validation minimale
- ⭐ **< 8000 opérations** : bonne performance
- 🏆 **< 5500 opérations** : performance excellente

## Opérations disponibles

| Opération | Description |
|-----------|-------------|
| `sa` | Swap les 2 premiers éléments de la pile a |
| `sb` | Swap les 2 premiers éléments de la pile b |
| `ss` | `sa` et `sb` simultanément |
| `pa` | Push le premier élément de b vers a |
| `pb` | Push le premier élément de a vers b |
| `ra` | Rotate a (le premier élément devient le dernier) |
| `rb` | Rotate b (le premier élément devient le dernier) |
| `rr` | `ra` et `rb` simultanément |
| `rra` | Reverse rotate a (le dernier élément devient le premier) |
| `rrb` | Reverse rotate b (le dernier élément devient le premier) |
| `rrr` | `rra` et `rrb` simultanément |

## Structure du projet

```
push_swap
├── algorithms
│   ├── adaptive
│   │   ├── adaptive.c
│   │   └── adaptive.h
│   ├── algorithme_complexe
│   │   ├── algorithme_complexe.c
│   │   └── algorithme_complexe.h
│   ├── algorithme_medium
│   │   ├── algorithme_medium1.c
│   │   ├── algorithme_medium.h
│   │   ├── utils1.c
│   │   └── utils2.c
│   └── algorithm_simple
│       ├── algorithme_simple1.c
│       ├── algorithme_simple.h
│       └── utils.c
├── bonus
│   ├── checker.c
│   ├── checker_utils.c
│   ├── gnl
│   │   ├── get_next_line.c
│   │   ├── get_next_line.h
│   │   └── get_next_line_utils.c
│   ├── operations
│   │   ├── operations1.c
│   │   ├── operations2.c
│   │   ├── operations3.c
│   │   ├── operations4.c
│   │   └── operations.h
│   └── parsing
│       ├── parse.c
│       ├── parse_numbers.c
│       └── parse_utils.c
├── libft
│   ├── ft_atol.c
│   ├── ft_isdigit.c
│   ├── ft_putstr_fd.c
│   ├── ft_split.c
│   ├── ft_strcmp.c
│   ├── ft_strcpy.c
│   ├── ft_strdup.c
│   ├── ft_strjoin.c
│   ├── ft_strlen.c
│   ├── libft.h
│   └── Makefile
├── main
│   ├── display_utils2.c
│   ├── display_utils.c
│   ├── main.c
│   ├── main.h
│   └── main_test.c
├── Makefile
├── operations
│   ├── operations1.c
│   ├── operations2.c
│   ├── operations3.c
│   ├── operations4.c
│   └── operations.h
├── parsing
│   ├── parse.c
│   ├── parse_flags.c
│   ├── parse.h
│   ├── parse_numbers.c
│   └── parse_utils.c
├── README.md
└── stack
    ├── stack.h
    ├── stack_utils1.c
    └── stack_utils2.c
```

## Gestion des erreurs

Le programme affiche `Error` suivi d'un retour à la ligne sur la sortie d'erreur standard dans les cas suivants :
- Arguments non entiers
- Entiers hors de la plage valide (INT_MIN à INT_MAX)
- Valeurs dupliquées
- Chaînes vides

## Contributions

### [ton_login]
- Implémentation des algorithmes Simple et Medium
- Gestion du parsing et des erreurs
- Tests et validation sur 100 nombres

### [login_partenaire]
- Implémentation des algorithmes Complex et Adaptatif
- Calcul de la métrique de désordre
- Tests et validation sur 500 nombres
- Développement du checker (bonus)

*Les deux membres ont collaboré sur l'architecture générale, le debugging et l'optimisation des performances.*

## Ressources

### Documentation officielle et références classiques
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) - Complexités algorithmiques
- [Visualgo](https://visualgo.net/en/sorting) - Visualisation d'algorithmes de tri
- [Sorting Algorithms Animations](https://www.toptal.com/developers/sorting-algorithms) - Comparaisons visuelles
- [Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/) - Référence académique
- [GeeksforGeeks - Radix Sort](https://www.geeksforgeeks.org/radix-sort/) - Documentation du radix sort

### Articles et tutoriels spécifiques
- [Push_swap : A Journey to Find the Most Efficient Sorting Algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Complexity Analysis for Two-Stack Sorting](https://stackoverflow.com/questions/tagged/push-swap)

### Utilisation de l'IA

L'intelligence artificielle a été utilisée de manière assistive sur ce projet pour les tâches suivantes :

#### ✅ Utilisations appropriées :
1. **Génération de tests** : Création de scripts de tests automatisés pour valider les algorithmes
2. **Debugging** : Identification de bugs logiques dans les fonctions de rotation
3. **Optimisation de code** : Suggestions pour réduire les opérations redondantes
4. **Documentation** : Aide à la rédaction du README et des commentaires de code
5. **Recherche de ressources** : Suggestions de documentation et d'articles pertinents

#### 🚫 Limites respectées :
- Aucune génération complète de fonctions sans compréhension
- Validation systématique avec les pairs de tout code suggéré
- Réécriture personnelle de tout algorithme proposé
- Tests approfondis de toute suggestion avant intégration

#### 🎯 Méthodologie appliquée :
1. Réflexion initiale sur le problème avant toute consultation d'IA
2. Formulation de prompts précis avec contexte technique
3. Revue critique de chaque suggestion reçue
4. Discussion avec le binôme sur les approches proposées
5. Implémentation manuelle après compréhension complète

**Outils utilisés :** Claude (Anthropic), ChatGPT (pour comparaisons d'approches)

**Conclusion :** L'IA a servi d'assistant pour accélérer certaines tâches répétitives et fournir des perspectives alternatives, mais toute la logique algorithmique et l'architecture du projet ont été conçues et comprises par les membres du groupe.

---

**Date de réalisation :** Janvier 2026  
**École :** 42  
**Langage :** C  
**Note minimale :** 100/100 (objectif)