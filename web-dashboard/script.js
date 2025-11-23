async function loadAQIData() {
    const response = await fetch("sensor_data.json");
    const data = await response.json();

    const container = document.getElementById("aqi-container");
    container.innerHTML = "";

    for (let sector in data) {
        let aqi = data[sector].aqi;
        let status = "";
        
        if (aqi > 150) status = "poor";
        else if (aqi > 100) status = "moderate";
        else status = "good";

        container.innerHTML += `
            <div class="card ${status}">
                <h2>${sector}</h2>
                <p>AQI: <b>${aqi}</b></p>
                <p>LED Status: <b>${aqi > 150 ? "ON" : "OFF"}</b></p>
            </div>
        `;
    }
}

loadAQIData();
setInterval(loadAQIData, 5000);
