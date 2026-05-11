// Mermaid diagram renderer for Remark.js slides
// This script must be loaded after remark.create() and mermaid.min.js
// Handles .mermaid[<pre>...</pre>] and .mermaid[direct text] patterns
(function () {
  'use strict';

  // Initialize Mermaid
  mermaid.initialize({
    startOnLoad: false,
    theme: 'forest',
    themeCSS:
      '.tick>text { font-size:26px; }  .taskTextOutsideRight,.taskTextOutsideLeft { font-size:20px; } .titleText {font-size:30px;} .sectionTitle {font-size:20px;}',
    flowchart: {
      useMaxWidth: true,
      htmlLabels: true,
    },
    gantt: {
      fontSize: 26,
      barHeight: 30,
      useMaxWidth: false,
    },
  });

  // Find and render all Mermaid diagrams
  var mermaidCmps = document.querySelectorAll('.mermaid');
  var len = mermaidCmps.length;
  for (var i = 0; i < len; i++) {
    var mermaidCmp = mermaidCmps[i];
    // Skip already rendered diagrams
    if (mermaidCmp.querySelector('svg')) continue;

    // Extract diagram definition: prefer <pre> content, fallback to direct text
    var graphDefinition = '';
    var preCmps = mermaidCmp.querySelectorAll('pre');
    if (preCmps.length > 0) {
      for (var j = 0; j < preCmps.length; j++) {
        graphDefinition += preCmps[j].textContent;
      }
    } else {
      graphDefinition = mermaidCmp.textContent.trim();
    }

    if (!graphDefinition) continue;

    // Render with IIFE to capture loop variables correctly
    (function (cmp, id, def) {
      try {
        cmp.innerHTML = '';
        mermaid.mermaidAPI.render(id, def, function (svgCode, bindFunctions) {
          cmp.innerHTML = svgCode;
          if (typeof bindFunctions === 'function') {
            bindFunctions(cmp);
          }
        });
      } catch (e) {
        console.error('Mermaid render error for', id, ':', e);
        cmp.innerHTML =
          '<p style="color:red; padding:1em; text-align:center;">Diagram render error</p>';
      }
    })(mermaidCmp, 'mermaidGraph' + i, graphDefinition);
  }
})();
