# Why HPWL is Bad? 🚫📏

## Presentation Outline 🗒️
1. Introduction to HPWL
2. Clock Tree Synthesis Perspective ⏰
3. Retiming Perspective 🔄
4. The HPWL Problem ❌
5. Better Approaches ✅
6. Q&A ❓

---

## 1. What is HPWL? 📏

**Half-Perimeter Wire Length** - A common metric for estimating wire length in physical design

HPWL = (max_x - min_x) + (max_y - min_y)

**Key Issues:**
- 🎯 Poor topology prediction
- 📈 Underestimates multi-pin nets
- 🔀 Misses critical routing paths
- ⏱️ Weak delay correlation

## 2. Clock Tree Synthesis Perspective ⏰

**Goal:** Create balanced clock trees

- Elmore delay model is not accurate, but "good enough" ✅

---

## 3. Retiming Perspective 🔄

**Goal:** Optimize flip-flop positions

- Wire-load model is not accurate, but "good enough" ✅

---

## 4. The HPWL Problem ❌

**What We Want:**

```
        # OUT
        |
    #---o
        |
        +--------O------+
               IN       | 
                        o-----#
                        |
                        #
```

**What We Get:**

```
                 # OUT
                 |
              +--o------------#
     IN       |
    O---------o
              | 
              o------#
              |   
              #
```


---

## 5. Better Approaches ??? 

1. **Steiner Wire Length** 🌲
   - More accurate for multi-pin nets
   - Better topology prediction

2. **Routability-Aware Metrics** 🗺️
   - Congestion estimation
   - Layer-aware costing

3. **Look-Ahead Routing** 🔮
   - Fast global routing
   - Real RC extraction


