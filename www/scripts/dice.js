class RollingDice extends HTMLElement {
    wrapper = document.createElement('div');

    static toggleClasses(die) {
        die.classList.toggle("odd-roll");
        die.classList.toggle("even-roll");
    }

    static getRandomNumber(min, max) {
        min = Math.ceil(min);
        max = Math.floor(max);
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }

    rollDice() {
        const dice = this.querySelectorAll(".die-list");
        console.log("roll....");

        dice.forEach(die => {
            RollingDice.toggleClasses(die);
            die.dataset.roll = RollingDice.getRandomNumber(1, 6);
        });
    }

    constructor() {
        // Always call super first in constructor
        super();

        // Create a shadow root
        const shadow = this.attachShadow({mode: 'open'});

        // Create div
        //this.wrapper = document.createElement('div');
        this.wrapper.classList.add("dice");

        this.wrapper.innerHTML = "<ol class=\"die-list even-roll\" data-roll=\"1\" id=\"die-1\">\n" +
            "        <li class=\"die-item\" data-side=\"1\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"2\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"3\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"4\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"5\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"6\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "      </ol>\n" +
            "      <ol class=\"die-list odd-roll\" data-roll=\"1\" id=\"die-2\">\n" +
            "        <li class=\"die-item\" data-side=\"1\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"2\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"3\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"4\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"5\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "        <li class=\"die-item\" data-side=\"6\">\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "          <span class=\"dot\"></span>\n" +
            "        </li>\n" +
            "      </ol>";

        // Create some CSS to apply to the shadow dom
        const style = document.createElement('style');
        console.log(style.isConnected);

        style.textContent = "* {\n" +
            "  margin: 0;\n" +
            "  padding: 0;\n" +
            "  vertical-align: baseline;\n" +
            "}\n" +
            "html {\n" +
            "  font-family: system-ui, sans-serif;\n" +
            "}\n" +
            "body {\n" +
            "  background: linear-gradient(#545454, #454545, #676767);\n" +
            "  display: grid;\n" +
            "  grid-template-columns: 1fr;\n" +
            "  height: 100vh;\n" +
            "  overflow: hidden;\n" +
            "  width: 100%;\n" +
            "}\n" +
            ".dice {\n" +
            "  align-items: center;\n" +
            "  display: grid;\n" +
            "  grid-gap: 2rem;\n" +
            "  grid-template-columns: repeat(auto-fit, minmax(8rem, 1fr));\n" +
            "  grid-template-rows: auto;\n" +
            "  justify-items: center;\n" +
            "  padding: 2rem;\n" +
            "  perspective: 600px;\n" +
            "  width: 100%;\n" +
            "}\n" +
            ".die-list {\n" +
            "  display: grid;\n" +
            "  grid-template-columns: 1fr;\n" +
            "  grid-template-rows: 1fr;\n" +
            "  height: 6rem;\n" +
            "  list-style-type: none;\n" +
            "  transform-style: preserve-3d;\n" +
            "  width: 6rem;\n" +
            "}\n" +
            ".even-roll {\n" +
            "  transition: transform 1.5s ease-out;\n" +
            "}\n" +
            ".odd-roll {\n" +
            "  transition: transform 1.25s ease-out;\n" +
            "}\n" +
            ".die-item {\n" +
            "  background-color: #fefefe;\n" +
            "  box-shadow: inset -0.35rem 0.35rem 0.75rem rgba(0, 0, 0, 0.3),\n" +
            "    inset 0.5rem -0.25rem 0.5rem rgba(0, 0, 0, 0.15);\n" +
            "  display: grid;\n" +
            "  grid-column: 1;\n" +
            "  grid-row: 1;\n" +
            "  grid-template-areas:\n" +
            "    \"one two three\"\n" +
            "    \"four five six\"\n" +
            "    \"seven eight nine\";\n" +
            "  grid-template-columns: repeat(3, 1fr);\n" +
            "  grid-template-rows: repeat(3, 1fr);\n" +
            "  height: 100%;\n" +
            "  padding: 1rem;\n" +
            "  width: 100%;\n" +
            "}\n" +
            ".dot {\n" +
            "  align-self: center;\n" +
            "  background-color: #676767;\n" +
            "  border-radius: 50%;\n" +
            "  box-shadow: inset -0.15rem 0.15rem 0.25rem rgba(0, 0, 0, 0.5);\n" +
            "  display: block;\n" +
            "  height: 1.25rem;\n" +
            "  justify-self: center;\n" +
            "  width: 1.25rem;\n" +
            "}\n" +
            ".even-roll[data-roll=\"1\"] {\n" +
            "  transform: rotateX(360deg) rotateY(720deg) rotateZ(360deg);\n" +
            "}\n" +
            ".even-roll[data-roll=\"2\"] {\n" +
            "  transform: rotateX(450deg) rotateY(720deg) rotateZ(360deg);\n" +
            "}\n" +
            ".even-roll[data-roll=\"3\"] {\n" +
            "  transform: rotateX(360deg) rotateY(630deg) rotateZ(360deg);\n" +
            "}\n" +
            ".even-roll[data-roll=\"4\"] {\n" +
            "  transform: rotateX(360deg) rotateY(810deg) rotateZ(360deg);\n" +
            "}\n" +
            ".even-roll[data-roll=\"5\"] {\n" +
            "  transform: rotateX(270deg) rotateY(720deg) rotateZ(360deg);\n" +
            "}\n" +
            ".even-roll[data-roll=\"6\"] {\n" +
            "  transform: rotateX(360deg) rotateY(900deg) rotateZ(360deg);\n" +
            "}\n" +
            ".odd-roll[data-roll=\"1\"] {\n" +
            "  transform: rotateX(-360deg) rotateY(-720deg) rotateZ(-360deg);\n" +
            "}\n" +
            ".odd-roll[data-roll=\"2\"] {\n" +
            "  transform: rotateX(-270deg) rotateY(-720deg) rotateZ(-360deg);\n" +
            "}\n" +
            ".odd-roll[data-roll=\"3\"] {\n" +
            "  transform: rotateX(-360deg) rotateY(-810deg) rotateZ(-360deg);\n" +
            "}\n" +
            ".odd-roll[data-roll=\"4\"] {\n" +
            "  transform: rotateX(-360deg) rotateY(-630deg) rotateZ(-360deg);\n" +
            "}\n" +
            ".odd-roll[data-roll=\"5\"] {\n" +
            "  transform: rotateX(-450deg) rotateY(-720deg) rotateZ(-360deg);\n" +
            "}\n" +
            ".odd-roll[data-roll=\"6\"] {\n" +
            "  transform: rotateX(-360deg) rotateY(-900deg) rotateZ(-360deg);\n" +
            "}\n" +
            "[data-side=\"1\"] {\n" +
            "  transform: rotate3d(0, 0, 0, 90deg) translateZ(4rem);\n" +
            "}\n" +
            "[data-side=\"2\"] {\n" +
            "  transform: rotate3d(-1, 0, 0, 90deg) translateZ(4rem);\n" +
            "}\n" +
            "[data-side=\"3\"] {\n" +
            "  transform: rotate3d(0, 1, 0, 90deg) translateZ(4rem);\n" +
            "}\n" +
            "[data-side=\"4\"] {\n" +
            "  transform: rotate3d(0, -1, 0, 90deg) translateZ(4rem);\n" +
            "}\n" +
            "[data-side=\"5\"] {\n" +
            "  transform: rotate3d(1, 0, 0, 90deg) translateZ(4rem);\n" +
            "}\n" +
            "[data-side=\"6\"] {\n" +
            "  transform: rotate3d(1, 0, 0, 180deg) translateZ(4rem);\n" +
            "}\n" +
            "[data-side=\"1\"] .dot:nth-of-type(1) {\n" +
            "  grid-area: five;\n" +
            "}\n" +
            "[data-side=\"2\"] .dot:nth-of-type(1) {\n" +
            "  grid-area: one;\n" +
            "}\n" +
            "[data-side=\"2\"] .dot:nth-of-type(2) {\n" +
            "  grid-area: nine;\n" +
            "}\n" +
            "[data-side=\"3\"] .dot:nth-of-type(1) {\n" +
            "  grid-area: one;\n" +
            "}\n" +
            "[data-side=\"3\"] .dot:nth-of-type(2) {\n" +
            "  grid-area: five;\n" +
            "}\n" +
            "[data-side=\"3\"] .dot:nth-of-type(3) {\n" +
            "  grid-area: nine;\n" +
            "}\n" +
            "[data-side=\"4\"] .dot:nth-of-type(1) {\n" +
            "  grid-area: one;\n" +
            "}\n" +
            "[data-side=\"4\"] .dot:nth-of-type(2) {\n" +
            "  grid-area: three;\n" +
            "}\n" +
            "[data-side=\"4\"] .dot:nth-of-type(3) {\n" +
            "  grid-area: seven;\n" +
            "}\n" +
            "[data-side=\"4\"] .dot:nth-of-type(4) {\n" +
            "  grid-area: nine;\n" +
            "}\n" +
            "[data-side=\"5\"] .dot:nth-of-type(1) {\n" +
            "  grid-area: one;\n" +
            "}\n" +
            "[data-side=\"5\"] .dot:nth-of-type(2) {\n" +
            "  grid-area: three;\n" +
            "}\n" +
            "[data-side=\"5\"] .dot:nth-of-type(3) {\n" +
            "  grid-area: five;\n" +
            "}\n" +
            "[data-side=\"5\"] .dot:nth-of-type(4) {\n" +
            "  grid-area: seven;\n" +
            "}\n" +
            "[data-side=\"5\"] .dot:nth-of-type(5) {\n" +
            "  grid-area: nine;\n" +
            "}\n" +
            "[data-side=\"6\"] .dot:nth-of-type(1) {\n" +
            "  grid-area: one;\n" +
            "}\n" +
            "[data-side=\"6\"] .dot:nth-of-type(2) {\n" +
            "  grid-area: three;\n" +
            "}\n" +
            "[data-side=\"6\"] .dot:nth-of-type(3) {\n" +
            "  grid-area: four;\n" +
            "}\n" +
            "[data-side=\"6\"] .dot:nth-of-type(4) {\n" +
            "  grid-area: six;\n" +
            "}\n" +
            "[data-side=\"6\"] .dot:nth-of-type(5) {\n" +
            "  grid-area: seven;\n" +
            "}\n" +
            "[data-side=\"6\"] .dot:nth-of-type(6) {\n" +
            "  grid-area: nine;\n" +
            "}\n" +
            "@media (min-width: 900px) {\n" +
            "  .dice {\n" +
            "    perspective: 1300px;\n" +
            "  }\n" +
            "}\n";

        // Attach the created elements to the shadow dom
        shadow.appendChild(style);
        console.log(style.isConnected);
        shadow.appendChild(this.wrapper);

        this.wrapper.addEventListener("click", this.rollDice);
    };
}

// Define the new element
customElements.define('rolling-dice', RollingDice);