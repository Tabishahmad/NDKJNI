package com.app.ndktest

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.app.ndktest.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()
        passparam("0")

        callKotlinMethod()
    }
    fun javaMethod(message: String) {
        // Do something with the message in Java
        Log.d("MyActivity", "Received message from C++: $message")
    }
    /**
     * A native method that is implemented by the 'ndktest' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun apiKey(): String
    external fun passparam(string: String):String
    external fun callKotlinMethod()
    companion object {
        // Used to load the 'ndktest' library on application startup.
        init {
            System.loadLibrary("ndktest")
        }
        @JvmStatic
        fun yourKotlinMethod() {
            // Your Kotlin method implementation goes here
            // For example, you can show a toast
            // Or update UI elements
            println("yourKotlinMethod")
        }
    }
}