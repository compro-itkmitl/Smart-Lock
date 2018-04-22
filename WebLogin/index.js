firebase.auth().onAuthStateChanged(function(user) {
  if (user) {
    // status when user login

    document.getElementById("user_div").style.display = "block";
    document.getElementById("login_div").style.display = "none";

    var user = firebase.auth().currentUser;

    if(user != null){

      var email_id = user.email;
      document.getElementById("user_para").innerHTML = "Welcome User : " + email_id;

    }

  } else {
    // No user is login

    document.getElementById("user_div").style.display = "none";
    document.getElementById("login_div").style.display = "block";

  }
});

function login(){

  var userEmail = document.getElementById("email_field").value;
  var userPass = document.getElementById("password_field").value;

  firebase.auth().signInWithEmailAndPassword(userEmail, userPass).catch(function(error) {
    // Handle Errors
    var errorCode = error.code;
    var errorMessage = error.message;

    window.alert("Error : " + errorMessage);
  });

}

function logout(){
  firebase.auth().signOut();
}

function forget(){

    var userEmail = document.getElementById("email_field").value;

    firebase.auth().sendPasswordResetEmail(userEmail).then(function () {
      alert('Password Reset Email Sent');
    }).catch(function(error){

      var errorCode = error.code;
      var errorMessage = error.message;

      if (errorCode == 'auth/invalid-email'){
          alert(errorMessage);
      }
      else if (errorCode == 'auth/invalid-email'){
          alert(errorMessage)
      }
      console.log(error)
    })
}



var onBtn = document.getElementById("onBtn");
var offBtn = document.getElementById("offBtn");

function on(){

  var firebaseRef = firebase.database().ref();

  firebaseRef.child("status").set(0);
 
}

function off(){
  
    var firebaseRef = firebase.database().ref();
  
    firebaseRef.child("status").set(1);
  
  }
