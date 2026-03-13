// Displaying welcome message on page load
window.onload = function () {
    alert("Welcome to Bigby's Portfolio!");
};

// to change background color when button is clicked
document.getElementById("changeColor").addEventListener("click", function () {
    document.body.style.backgroundColor = "#" + Math.floor(Math.random() * 16777215).toString(16);
});

// Form validation
document.getElementById("contactForm").addEventListener("submit", function (event) {
    let name = document.getElementById("name").value;
    let email = document.getElementById("email").value;
    let message = document.getElementById("message").value;

    if (name === "" || email === "" || message === "") {
        alert("Please fill out all fields.");
        event.preventDefault();
    } else {
        alert("Message sent successfully!");
    }
});
