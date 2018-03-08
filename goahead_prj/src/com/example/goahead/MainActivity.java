package com.example.goahead;

import android.app.Activity;
import android.os.Bundle;

import com.jni.libgo.NDKgoahead;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		new NDKgoahead().StartGoaheadServer();
	}
}
