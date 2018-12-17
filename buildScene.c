void buildScene(void)
{
 // Sets up all objets in the scene. This involves creating each object,
 // defining the transformations needed to shape and position it as
 // desired, specifying the reflectance properties (albedos and colours)
 // and setting up textures where needed.
 //
 // NOTE: Light sources are now EXCLUSIVELY area light sources. They are
 //       defined by regular objects whose 'isLightSource' flag is set
 //       to 1. Therefore, you can create light sources with any shape
 //       and colour using the same object primitives and transforms
 //       you're using to set up the scene.
 //
 // To create hierarchical objects:
 //    You must keep track of transformations carried out by parent objects
 //    as you move through the hierarchy. Declare and manipulate your own
 //    transformation matrices (use the provided functions in utils.c to
 //    compound transformations on these matrices). When declaring a new
 //    object within the hierarchy
 //    - Initialize the object
 //    - Apply any object-level transforms to shape/rotate/resize/move
 //      the object using regular object transformation functions
 //    - Apply the transformations passed on from the parent object
 //      by pre-multiplying the matrix containing the parent's transforms
 //      with the object's own transformation matrix.
 //    - Compute and store the object's inverse transform as usual.
 //
 // NOTE: After setting up the transformations for each object, don't
 //       forget to set up the inverse transform matrix!

 struct object3D *o;
 struct point3D p;

 // Cornell box
 o=newSphere(1.0,0.0,0.0,.75,.25,.25,.05,1.4);	// Left
 Scale(o,500,500,500);
 Translate(o,-510,0,5);
 invert(&o->T[0][0],&o->Tinv[0][0]);
 insertObject(o,&object_list);

 o=newSphere(1.0,0.0,0.0,.25,.25,.75,.05,1.4);		// Right
 Scale(o,500,500,500);
 Translate(o,510,0,5);
 invert(&o->T[0][0],&o->Tinv[0][0]);
 insertObject(o,&object_list);

 o=newSphere(1.0,0.0,0.0,.25,.75,.75,.05,1.4);		// Back
 Scale(o,500,500,500);
 Translate(o,0,0,515);
 invert(&o->T[0][0],&o->Tinv[0][0]);
 insertObject(o,&object_list);

 o=newSphere(1.0,0.0,0.0,.75,.25,.75,.02,1.4);	// Bottom
 Scale(o,500,500,500);
 Translate(o,0,-510,5);
 invert(&o->T[0][0],&o->Tinv[0][0]);
 insertObject(o,&object_list);

 o=newSphere(1.0,0.0,0.0,.75,.75,.25,.05,1.4);		// Top
 Scale(o,500,500,500);
 Translate(o,0,510,5);
 invert(&o->T[0][0],&o->Tinv[0][0]);
 insertObject(o,&object_list);

 // Note the parameters: diff, refl, trans, R, G, B, reflspread,r_index)
 o=newSphere(0,1.0,0,0.99,.99,.99,.05,1.4);		// Inner
 Scale(o,1.75,1.75,1.75);		
 Translate(o,0,7.0,8.5);
 invert(&o->T[0][0],&o->Tinv[0][0]);		
insertObject(o,&object_list);

 o=newSphere(0,1.0,0,0.99,.99,.99,.05,1.4);		// inner center
 Scale(o,1.75,1.75,1.75);		
 Translate(o,0,1.0,8.5);
 invert(&o->T[0][0],&o->Tinv[0][0]);		
insertObject(o,&object_list);


for(int i = 1; i<5;i++){
 o=newSphere(0.2*i,1-(0.2*i),0,0,.7-.1*i,.7,.05,1.4);		// left 1-5
 Scale(o,1.75,1.75,1.75);		
 Translate(o,-1.7*i,7-2.8*i,8.5-i);
 invert(&o->T[0][0],&o->Tinv[0][0]);		
insertObject(o,&object_list);

 o=newSphere(0,1-(0.2*i),0.2*i,0,.7,.7-.1*i,.05,1.4);		// right 1-5
 Scale(o,1.75,1.75,1.75);		
 Translate(o,1.7*i,7-2.8*i,8.5-i);
 invert(&o->T[0][0],&o->Tinv[0][0]);		
insertObject(o,&object_list);
}
//  o=newSphere(.4,.6,0,0,.5,.7,.05,1.4);	// left 2
//  Scale(o,6,6,1);		
//  Translate(o,-12,15,24);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);

//  o=newSphere(.45,.75,.55,0.4,0,.7,.5,.8,1.2,8);		// right 2
//  Scale(o,6,6,1);		
//  Translate(o,12,15,24);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);

//  o=newSphere(.6,.4,0,0,.5,.7,.05,1.4);		// left 3
//  Scale(o,6,6,1);		
//  Translate(o,-15,11,19);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);

//  o=newSphere(.35,.65,.45,0.35,0,.7,.4,.7,1.3,7);		// right 3
//  Scale(o,6,6,1);		
//  Translate(o,15,11,19);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);

//  o=newSphere(.25,.55,.35,0.3,0,.3,.7,.6,1.4,6);		// left 4
// o->alphaMapped=1;
//  Scale(o,6,6,1);		
//  Translate(o,-17,7,14);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);

//  o=newSphere(.25,.55,.35,0.3,0,.7,.3,.6,1.4,6);		// right 4
// o->alphaMapped=1;
//  Scale(o,6,6,1);		
//  Translate(o,17,7,14);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);

//  o=newSphere(.15,.45,.25,0.2,0,.2,.7,.5,1.5,5);		// left 5
// o->normalMapped=1;
//  Scale(o,6,6,1);		
//  Translate(o,-19,4,10);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);

//  o=newSphere(.15,.45,.25,0.2,0,.7,.2,.5,1.5,5);		// right 5
// o->normalMapped=1;
//  Scale(o,6,6,1);		
//  Translate(o,19,4,10);
//  invert(&o->T[0][0],&o->Tinv[0][0]);		
// insertObject(o,&object_list);


/*
 // Ring of refracting spheres
 for (int i=0; i<5;i++)
 {
  o=newSphere(0.0,0.0,1.0,.99,.99,.99,.01,1.45+(.1*i));
  Scale(o,1.75,1.75,1.75);
  Translate(o,3.25*cos(2*PI*i/5),-2.45,3+3.25*sin(2*PI*i/5));
  invert(&o->T[0][0],&o->Tinv[0][0]);
  insertObject(o,&object_list);
 }

 for (int i=0; i<7;i++)
 {
  o=newSphere(0.0,0.0,1.0,.99,.99,.99,.01,2.00+(.05*i));
  Scale(o,1.75,1.75,1.75);
  Translate(o,4.60*cos(2*PI*i/7),-6.35,3+4.60*sin(2*PI*i/7));
  invert(&o->T[0][0],&o->Tinv[0][0]);
  insertObject(o,&object_list);
 }
*/

 // Planar light source at top
 o=newPlane(1.00,0.00,0.0,1.0,1.0,1.0,0.0,1.54);
 Scale(o,.5,2.5,1);
 RotateX(o,PI/2);
 Translate(o,0,9.995,5);
 invert(&o->T[0][0],&o->Tinv[0][0]);
 o->isLightSource=1;
 insertObject(o,&object_list);
}

