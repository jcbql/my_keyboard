These two posts are an excellent starting point for the keyboard layout rabbit hole:
- [Tour of split ergo keyboards](https://getreuer.info/posts/keyboards/tour/index.html)
- [A guide to alt keyboard layouts (why, how, which one?)](https://getreuer.info/posts/keyboards/alt-layouts/index.html)

## My journey
I bought the Corne v4 keyboard knowing that I'd be forced to learn how to properly touch type. Since I had to go through the effort regardless, why not take the time to learn a better layout than qwerty?

This spawned many hours of reading through the literature that's already out there. The [keyboard layouts doc](https://docs.google.com/document/d/1W0jhfqJI2ueJ2FNseR4YAFpNfsUM-_FlREHbpNGmC2o) is a brilliant resource.

As my Corne arrived sooner rather than later, I decided to go the "safe" route and put Colemak DH on it.

After nearly half a year of practice and reaching a typing speed above 60 words-per-minute (wpm) with Colemak DH, I wanted more. I was especially intrigued by putting a letter on a thumb key. One of the advantages of that a split keyboard unlocks.

## How the SNTLF layout came to be
I was mostly interested in the [Enthium](https://github.com/sunaku/enthium) and [Hands Down Promethium](https://www.reddit.com/r/KeyboardLayouts/comments/1g66ivi/hands_down_promethium_snth_meets_hd_silverengram/) layout. Putting the vowels on the index, middle, and ring fingers appealed much more to me than the Galium/Graphite vowel blocks.

I started with a flipped [Enthium v7 layout](https://github.com/sunaku/enthium/releases/tag/v7) as shown below. I flipped it as I was already used to having the vowels on the right hand from Colemak DH. I also put R on the right hand as I'm used to using space with the left thumb.

```
  z w d l x  - u o y q
v s n t h k  , a e i c b
  f p g m j  ; . = / '
             r
```

After fiddling with the cyanophage's fantastic [Keyboard Layout Stats](https://cyanophage.github.io/) website, I came up with the following changes.

### Swap B and W (and P)
By swapping B and W, you can completely remove the WN SFB. It's -0.05% SFB for slightly higher left pinky usage.

After that I also swapped P and B since it's more comfortable for me to reach up and P has higher usage than B.

```
  z p d l x  - u o y q
v s n t h k  , a e i c w
  f b g m j  ; . = / '
             r
```

### Swap X, Z, and Q
While X isn't a common character, XP is the [most common bigram starting with X](https://norvig.com/mayzner.html). This turns XP into a nice in-roll.

I find the top pinky position less comfortable to type and Q is more common than Z.

```
  x p d l q  - u o y z
v s n t h k  , a e i c w
  f b g m j  ; . = / '
             r
```

### Rotate the LHM column
This change removes a bunch of scissors and 2U skip bigrams involving L.

More than half the time that you type H in English it's preceded by T ([source](https://norvig.com/mayzner.html)). If you remove all TH occurrences, H is only the 15th most common letter.

Given that I find the TH bigram equally comfortable to type with H on the bottom row, this change has no downsides.

```
  x p d m q  - u o y z
v s n t l k  , a e i c w
  f b g h j  ; . = / '
             r
```

### Reducing pinky movement
I move F to the center column in order to reduce the amount of movement for my left pinky. I put it next to L as LF and FL are semi-common bigrams. While you're supposed to type both of these with the index finger, this placement allows me to shift my hand and use the middle and index finger. LF and FL then roll nicely.

K, V and Q were moved to accommodate the change above.

```
  x p d m k  - u o y z
q s n t l f  , a e i c w
  v b g h j  ; . = / '
             r
```

### The final stretch
- Backspace is often repeatedly pressed. Why not use the strongest finger?
- The "Qu" button writes "qu" when pressed and "q" when held. In more than 92% percent of cases Q is followed by U [source](https://www.petercollingridge.co.uk/blog/language/analysing-english/bigrams/).