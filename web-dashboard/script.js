async function loadAQIData() {
    try {
        const response = await fetch('sensor_data.json?cache=' + Math.random());
        const data = await response.json();

        const container = document.getElementById('aqi-container');
        container.innerHTML = ""; // Clear old cards

        data.forEach((sector) => {
            const card = document.createElement('div');
            card.classList.add('card');

            // Color logic
            if (sector.aqi <= 100) {
                card.classList.add('good');
            } else if (sector.aqi <= 150) {
                card.classList.add('moderate');
            } else {
                card.classList.add('poor');
            }

            card.innerHTML = `
                <h2>${sector.name}</h2>
                <p><strong>AQI:</strong> ${sector.aqi}</p>
                <p><strong>LED Status:</strong> ${sector.led ? "ON" : "OFF"}</p>
            `;

            container.appendChild(card);
        });

    } catch (error) {
        console.log("Error loading AQI data:", error);
    }
}

// First load
loadAQIData();

// Auto-refresh every 5 seconds
setInterval(loadAQIData, 5000);
